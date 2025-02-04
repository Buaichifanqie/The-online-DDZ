#include <netinet/in.h>
#include <random>
#include <cassert>
#include "Communication.h"
#include "RsaCrypto.h"
#include "Log.h"
#include "information.pb.h"
#include "JsonParse.h"
#include "RoomList.h"


void Communication::parseRequest(Buffer* buf)
{
    // 读数据头
    std::string data = buf->data(sizeof(int));
    int length = *(int*)data.data();    // 大端长度
    // 读数据块
    length = ntohl(length);
    data = buf->data(length);
    if(m_aes)
    {
        data = m_aes->decrypt(data);
    }
    // 数据的反序列化
    Codec codec(data);
    Message resMsg;

    sendCallback myfunc =sendMessage;

    shared_ptr<Message> ptr = codec.decodeMsg();
    switch(ptr->reqcode)
    {
        case RequestCode::AesFenfa:
            handleAesFenfa(ptr.get(), resMsg);
            break;
        case RequestCode::UserLogin:
            handleLogin(ptr.get(), resMsg);
            Debug("回复给客户端的状态码: %d", resMsg.rescode);
            break;
        case RequestCode::Register:
            handleRegister(ptr.get(), resMsg);
            break;
        case RequestCode::AutoRoom:
        case RequestCode::ManualRoom:
            handleAddRoom(ptr.get(), resMsg);
            myfunc=std::bind(&Communication::readyForPlay,this,resMsg.roomName,placeholders::_1);
            break;
        default:
            break;
    }
    if(myfunc != nullptr)
    {
        codec.reLoad(&resMsg);
        std::string msg = codec.encodeMsg();
        //Debug("回复给客户端的数据: %s, size = %d, status: %d", msg.data(), msg.size(), resMsg.rescode);
        myfunc(msg);
    }
}

void Communication::handleAesFenfa(Message* reqMsg, Message& resMsg)
{
    RsaCrypto rsa;
    rsa.parseStringToKey(m_redis->rsaSecKey("PrivateKey"), RsaCrypto::PrivateKey);
    std::string aesKey = rsa.priKeyDecrypt(reqMsg->data1);
    // 哈希校验
    Hash h(HashType::Sha224);
    h.addData(aesKey);
    std::string res = h.result();

    resMsg.rescode = RespondCode::AesVerifyOK;
    if(reqMsg->data2 != res)
    {
        Debug("秘钥校验失败--aes");
        resMsg.rescode = RespondCode::Failed;
        resMsg.data1 = "Aes 秘钥的哈希校验失败了...";
    }
    else
    {
        m_aes = new AesCrypto(AesCrypto::AES_CBC_256, aesKey);
        Debug("秘钥校验成功了--aes");
    }
}

void Communication::setCallback(Communication::sendCallback func1, Communication::deleteCallback func2)
{
    sendMessage = func1;
    disconnect = func2;
}

void Communication::handleRegister(Message *reqMsg, Message &resMsg)
{
    // 查询数据库
    // select 字段 from 数据库表 where 条件;
    char sql[1024];
    sprintf(sql, "SELECT * FROM `user` WHERE `name`='%s';", reqMsg->userName.data());
    bool flag = m_mysql->query(sql);
    Debug("flag = %d, sql = %s", flag, sql);
    if(flag && !m_mysql->next())
    {
        // 将注册信息写入到数据库
        m_mysql->transaction();
        sprintf(sql, "INSERT INTO `user`(name, passwd, phone, date) VALUES('%s', '%s', '%s', NOW());",
                reqMsg->userName.data(), reqMsg->data1.data(), reqMsg->data2.data());
        bool fl1 = m_mysql->update(sql);
        Debug("fl1 = %d, sql = %s", fl1, sql);
        sprintf(sql, "INSERT INTO `information`(name, score, status) VALUES('%s', 0, 0);",
                reqMsg->userName.data());
        bool fl2 = m_mysql->update(sql);
        Debug("fl2 = %d, sql = %s", fl2, sql);
        if(fl1 && fl2)
        {
            m_mysql->commit();
            resMsg.rescode = RespondCode::RegisterOK;
        }
        else
        {
            m_mysql->rollback();
            resMsg.rescode = RespondCode::Failed;
            resMsg.data1 = "数据库插入数据失败!";
        }
    }
    else
    {
        resMsg.rescode = RespondCode::Failed;
        resMsg.data1 = "用户名已经存在, 无法完成注册!";
    }
}

Communication::Communication()
{
    JsonParse json;
    std::shared_ptr<DBInfo> info=json.getDatabaseInfo(JsonParse::Mysql);
    m_mysql=new MySqlConn;
    //连接数据库
    bool flag= m_mysql->connect(info->user,info->dbname,info->passwd,info->ip,info->port);
    assert(flag);
    m_redis=new Room;
    flag=m_redis->initEnvironment();
    assert(flag);
}

void Communication::handleLogin(Message *reqMsg, Message &resMsg)
{
    char sql[1024];
    sprintf(sql, "SELECT * FROM `user` WHERE `name`='%s' AND passwd='%s' AND (select  count(*) from information where name = '%s' AND status=0);", reqMsg->userName.data(),
            reqMsg->data1.data(), reqMsg->userName.data());
    bool flag = m_mysql->query(sql);
    if(flag && m_mysql->next())
    {
        m_mysql->transaction();
        sprintf(sql, "update `information` set status=1 WHERE `name`='%s'", reqMsg->userName.data());
        bool flag1 = m_mysql->update(sql);
        if(flag1)
        {
            m_mysql->commit();
            resMsg.rescode = RespondCode::LoginOK;
            Debug("用户登录成功了.....................................");
            return;
        }
        m_mysql->rollback();
    }
    resMsg.rescode = RespondCode::Failed;
    resMsg.data1 = "用户名或者密码错误, 或者当前用户已经成功登录了...";
}

Communication::~Communication() {
    if(m_redis)
    {
        delete m_redis;
    }
    if(m_mysql)
    {
        delete m_mysql;
    }
    if(m_aes)
    {
        delete m_aes;
    }
}

void Communication::handleAddRoom(Message *reqMsg, Message &resMsg) {
    //如果当前玩家不是第一次（登录之后的）加入房间
    std::string oldRoom=m_redis->WhereAmI(reqMsg->userName);
    //查询这个玩家上把加入的房间，然后把分数读出来
    int score=m_redis->playerScore(oldRoom,reqMsg->userName);
    bool flag= true;
    std::string roomName;
    if(reqMsg->reqcode == RequestCode::AutoRoom)
    {
        roomName = m_redis->joinRoom(reqMsg->userName);
    }
    else
    {
        roomName = reqMsg->roomName;
        flag = m_redis->joinRoom(reqMsg->userName, roomName);
    }
    //判断是否成功加入到某个房间
    if(flag)
    {
        //第一次加载分数,在redis中更新数据，最后将数据同步到mysql中
        if(score==0)
        {
            //查询mysql中的分数,并且存储到redis中
            std::string sql="select score from information where name='"+reqMsg->userName+"'";
            bool fl=m_mysql->query(sql);
            assert(fl);
            m_mysql->next();
            score=std::stoi(m_mysql->value(0));
        }
        m_redis->updatePlayerScore(roomName,reqMsg->userName,score);
        //将房间和玩家关系存储到单例对象中
        RoomList* roomList=RoomList::getInstance();
        roomList->addUser(roomName,reqMsg->userName,sendMessage);

        //给客户端回复数据
        resMsg.rescode = RespondCode::JoinRoomOK;
        resMsg.data1 =m_redis->getPlayerCount(roomName);
        resMsg.roomName=roomName;
    }
    else
    {
        resMsg.rescode = RespondCode::Failed;
        resMsg.data1 = "抱歉,加入房间失败了...人数已满";

    }
}

void Communication::readyForPlay(std::string roomName,std::string data) {
    //取出单例对象
    RoomList *instance = RoomList::getInstance();
    UserMap players = instance->getPlayers(roomName);
    if (players.size() < 3) {
        //房间没满
        for (auto item: players) {
            item.second(data);
        }
    }
    else
    {
        //房间满了
        //发牌数据
        dealCards(players);
        //通知客户端可以开始游戏了
        Message msg;
        msg.rescode=RespondCode::StartGame;
        //data1  userName-次序-分数  谁分数高谁优先抢地主
        msg.data1=m_redis->playersOder(roomName);
        Codec codec(&msg);
        for(const auto& item: players)
        {
            item.second(codec.encodeMsg());
        }
    }
}

void Communication::dealCards(UserMap players) {
    Message msg;
    //洗牌
    initCards();
    std::string &all=msg.data1;
    for(int i=0;i<51;++i)
    {
        //取牌
        auto card=takeOneCard();
        std::string sub=std::to_string(card.first)+"-"+std::to_string(card.second)+"#";
        all+=sub;
    }
    //剩余的牌
    std::string &lastCard=msg.data2;
    for(const auto& item: m_cards)
    {
        std::string sub=std::to_string(item.first)+"-"+std::to_string(item.second)+"#";
        lastCard+=sub;
    }
    msg.rescode=RespondCode::DealCards;
    Codec codec(&msg);
    //遍历当前房间中的所有玩家
    for(const auto& player: players)
    {
        player.second(codec.encodeMsg());
    }
}

void Communication::initCards() {
    //key-value (key值需要可以重复) multiMap
    m_cards.clear();
    //花色
    for(int i=1;i<=4;++i)
    {
        //点数
        for(int j=1;j<=13;++j)
        {
            m_cards.insert(make_pair(i,j));

        }
    }
    m_cards.insert(make_pair(0,14));
    m_cards.insert(make_pair(0,15));

}

std::pair<int, int> Communication::takeOneCard() {
    //生成随机数//遍历map容器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, m_cards.size()-1);
    int randNum=dis(gen);
    auto it=m_cards.begin();
    //遍历map容器
    for(int i=0;i<randNum;++i,++it);
    m_cards.erase(it);
    return *it;
}




