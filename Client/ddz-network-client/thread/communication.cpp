#include "communication.h"
#include "datamanager.h"
#include "rsacrypto.h"
#include <QThread>
#include <QDebug>
#include <QDateTime>
Communication::Communication(Message* msg,QObject *parent)
    : QObject{parent},m_msgInfo(msg)
{
    //设置自动销毁
    setAutoDelete(true);
}

void Communication::sendMessage(Message *msg,bool encrypt)
{
    //进行数据序列化
    Codec codec(msg);
    QByteArray data=codec.encodeMsg();
    //加密数据
    if(encrypt)
    {
        data=m_aes->encrypt(data);
    }
    //发送数据
    m_socket->sendMsg(data);
}

void Communication::parseRecvMessage()
{
    //接收数据
    // QByteArray data= m_socket->recvMsg(2);

    // 客户端：正确读取长度头
    // 客户端 Communication::parseRecvMessage
    QByteArray lenData = m_socket->recvMsg(4); // 先读4字节长度头
    if (lenData.size() != 4) return;
    uint32_t length = ntohl(*reinterpret_cast<const uint32_t*>(lenData.constData()));
    QByteArray data = m_socket->recvMsg(length); // 再读实际数据


    qDebug()<<"接收到数据:"<<"data";
    if(data.isEmpty())
    {
        return;
    }

    //反序列化数据
    Codec codc(data);
    QSharedPointer<Message> ptr=codc.decodeMsg();
    qDebug()<<ptr->rescode<<","<<ptr->data1<<","<<ptr->data2;
    //对Message结构体里服务器回复的状态码进行判断
    switch(ptr->rescode)
    {
    case RespondCode::LoginOK:
        emit loginOk();
        break;
    case RespondCode::RegisterOK:
        emit registerOk();
        break;
    case RespondCode::RsaFenFa:
        handleRsaFenfa(ptr.get());
        break;
    case RespondCode::AesVerifyOK:
        m_aes=new AesCrypto(AesCrypto::AES_CBC_256,m_aesKey,this);
        sendMessage(m_msgInfo);
        qDebug()<<"Aes的密钥分发成功了...";
    case RespondCode::Failed:
        emit failedMsg(ptr->data1);
    default:
        break;
    }
}

//密钥分发
void Communication::handleRsaFenfa(Message* msg)
{
    //校验签名
    RsaCrypto rsa;
    //解析公钥字符串
    rsa.parseStringToKey(msg->data1,RsaCrypto::PublicKey);
    //开始校验
    bool flag = rsa.verify(msg->data2,msg->data1);
    assert(flag);
    //生成对称加密的密钥
    // m_aesKey=generateAseKey(KeyLen::L32);
    // 客户端 handleRsaFenfa
    m_aesKey = generateAseKey(KeyLen::L32);


    //组织数据
    Message resMsg;
    resMsg.reqcode=RequestCode::AesFenfa;
    //resMsg.data1=rsa.pubKeyEncrypt(m_aesKey);
    resMsg.data1 = rsa.pubKeyEncrypt(m_aesKey); // 确保转为std::string

    resMsg.data2=QCryptographicHash::hash(m_aesKey,QCryptographicHash::Sha224).toHex();//16进制字符串的哈希
    //发送数据
    sendMessage(&resMsg,false);//sendMsg中有序列化的操作
}

QByteArray Communication::generateAseKey(KeyLen len)
{
    QByteArray time=QDateTime::currentDateTime().toString("yyyy.MM.dd-hh:mm:ss.zzz").toUtf8();
    //进行哈希计算
    QCryptographicHash hash(QCryptographicHash::Sha384);
    hash.addData(time);
    time=hash.result();
    time=time.left(len);
    return time;
}

void Communication::run()
{

    m_socket=new Tcpsocket;
    //连接服务器
    DataManager* obj=DataManager::getInstance();//单例对象
    bool flag= m_socket->connectToHost(obj->getIP(),obj->getPort().toInt());
    qDebug()<<"==============通信子线程的ID:"<<QThread::currentThread()<<"连接状态:"<<flag;
    if(!flag)
    {
        //通知主线程连接失败了
        emit connectFailed();
        delete m_socket;
        return;
    }
    //连接成功了
    while(!m_stop)
    {
        //处理服务器回复的数据

        //首先先得到非对称加密的公钥，发送加密之后的对称加密密钥给服务器，
        //服务器回复接收密钥成功的消息，然后发送登陆或者注册请求
        parseRecvMessage();
    }
    //服务器连接断开了 我们也让客户端断开连接
    m_socket->disConnect();
    delete m_socket;
}
