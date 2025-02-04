//
// Created by kongwenshuo on 25-1-30.
//

#include "Room.h"
#include "JsonParse.h"
#include "Log.h"


std::string Room::rsaSecKey(std::string filed) {
    auto value = m_redis->hget("RSA",filed);
    if(value.has_value())
    {
        return value.value();
    }
    return std::string();
}

void Room::clear() {
    //每次重启web服务器时重启
    m_redis->flushdb();
}

bool Room::initEnvironment() {
    JsonParse json;
    auto info=json.getDatabaseInfo(JsonParse::Redis);
    std::string connStr="tcp://"+info->ip+":"+std::to_string(info->port);
    m_redis=new sw::redis::Redis(connStr);
    //测试连接
    if(m_redis->ping()=="PONG")
    {
        Debug("成功连接了redis服务器...");
        return true;
    }
    return false;
}

Room::~Room() {
    if(m_redis)
    {
        delete m_redis;
    }
}

void Room::saveRsaSecKey(std::string filed, std::string value) {
    m_redis->hset("RSA",filed,value);
}

std::string Room::joinRoom(std::string userName) {
    std::optional<std::string> room;
    do{
        //scard
        if(m_redis->scard("TwoPlayer")>0)
        {
            //srandmember
            room= m_redis->srandmember("TwoPlayer");
            break;
        }
        if(m_redis->scard("OnePlayer")>0)
        {
            //srandmember
            room= m_redis->srandmember("OnePlayer");
            break;
        }
        //添加新房间
        room=getNewRoomName();
    }while(0);
    //加入到某个房间中
    joinRoom(userName,room.value());

    return room.value();
}

std::string Room::getNewRoomName() {
    //创建随机设备对象
    std::random_device rd;
    //创建随机数生成器对象
    std::mt19937 gen(rd());
    //创建均匀分布对象
    std::uniform_int_distribution<> dis(100000, 999999);
    //生成随机数
    int randomNum = dis(gen);
    return std::to_string(randomNum);
}

bool Room::joinRoom(std::string userName, std::string roomName) {
    if(m_redis->zcard(roomName)>=3)
    {
        return false;
    }
    //检查房间是否存在
    if(!m_redis->exists(roomName))
    {
        m_redis->sadd(OnePlayer,roomName);
    }
    //移动房间
    else if(m_redis->sismember(OnePlayer,roomName))
    {
        m_redis->smove(OnePlayer,TwoPlayer,roomName);
    }
    else if(m_redis->sismember(TwoPlayer,roomName))
    {
        m_redis->smove(TwoPlayer,ThreePlayer,roomName);
    }
    else
    {
        assert(false);//异常
    }
    //将玩家添加到房间 使用的结构是有序集合
    m_redis->zadd(roomName,userName,0);
    //将玩家存储起来用哈希->通过玩家找到房间
    m_redis->hset("PlayerRoom",userName,roomName);
    return false;
}

int Room::getPlayerCount(std::string roomName) {
    int count=m_redis->zcard(roomName);
    return count;
}

void Room::updatePlayerScore(std::string roomName, std::string userName, int score) {
    //更新->有序集合
    m_redis->zadd(roomName,userName,score);
}

std::string Room::WhereAmI(std::string userName) {
    auto value= m_redis->hget("PlayerRoom",userName);
    if(value.has_value())
    {
        return value.value();
    }
    return std::string();
}

int Room::playerScore(std::string roomName, std::string userName) {
    auto score= m_redis->zscore(roomName,userName);
    if(score.has_value())
    {
        return score.value();
    }
    return 0;
}

std::string Room::playersOder(std::string roomName) {
    int index = 0;
    std::string data;
    std::vector<std::pair<std::string, double>> output;
    // 对房间中的玩家进行排序, 降序排序zrevrange
    m_redis->zrevrange(roomName, 0, -1, std::back_inserter(output));
    for(auto& it:output)
    {
        data+=it.first+"-"+std::to_string(++index)+"-"+std::to_string((int)it.second)+"#";
    }
    return data;
    return std::string();
}
