#include "TcpConnection.h"
#include "HttpRequest.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Codec.h"
#include "Log.h"
#include "RsaCrypto.h"

int TcpConnection::processRead(void* arg)
{
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    // ��������
    int socket = conn->m_channel->getSocket();
    int count = conn->m_readBuf->socketRead(socket);

    Debug("���յ���http��������: %s", conn->m_readBuf->data());
    if (count > 0)
    {
        //��������������
        conn->m_reply->parseRequest(conn->m_readBuf);
    }
    else if(count<=0)
    {
        //�Ͽ��Ϳͻ��˵�����
        conn->addDeleteTask();
        Debug("�Ѿ��Ϳͻ��˶Ͽ�������");
    }
    return 0;
}

int TcpConnection::processWrite(void* arg)
{
    Debug("��ʼ����������(����д�¼�����)....");
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    // ��������
    int count = conn->m_writeBuf->sendData(conn->m_channel->getSocket());
    if (count > 0)
    {
        // �ж������Ƿ�ȫ�����ͳ�ȥ��
        if (conn->m_writeBuf->readableSize() == 0)
        {
            // 1. ���ټ��д�¼� -- �޸�channel�б�����¼�
            conn->m_channel->setCurrentEvent(FDEvent::ReadEvent);
            // 2. �޸�dispatcher���ļ��� -- �������ڵ�
            conn->m_evLoop->addTask(conn->m_channel, ElemType::MODIFY);
            Debug("���ݷ������....................");
        }
    }
    return 0;
}

int TcpConnection::destroy(void* arg)
{
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    if (conn != nullptr)
    {
        delete conn;
    }
    return 0;
}

TcpConnection::TcpConnection(int fd, EventLoop* evloop)
{
    m_evLoop = evloop;
    m_readBuf = new Buffer(10240);
    m_writeBuf = new Buffer(10240);

    m_reply=new Communication;

    auto delFunc=std::bind(&TcpConnection::addDeleteTask,this);
    auto writeFunc=std::bind(&TcpConnection::addWriteTask,this,std::placeholders::_1);
    m_reply->setCallback(writeFunc,delFunc);

    m_name = "Connection-" + to_string(fd);
    prepareSecreKey();
    m_channel = new Channel(fd, FDEvent::WriteEvent, processRead, processWrite, destroy, this);
    evloop->addTask(m_channel, ElemType::ADD);
}

TcpConnection::~TcpConnection()
{
    if (m_readBuf && m_readBuf->readableSize() == 0 &&
        m_writeBuf && m_writeBuf->readableSize() == 0)
    {
        delete m_readBuf;
        delete m_writeBuf;
        m_evLoop->freeChannel(m_channel);
    }
}

void TcpConnection::prepareSecreKey() {
    //����Կ
    ifstream ifs("public.pem");
    stringstream sstr;
    sstr<<ifs.rdbuf();
    string data=sstr.str();
    //��������
    Message msg;
    msg.rescode=RespondCode::RsaFenFa;
    msg.data1=data;
    RsaCrypto rsa("private.pem",RsaCrypto::PrivateKey);
    rsa.sign(data);
    msg.data2=data;
    Codec codec(&msg);
    data=codec.encodeMsg();
    //д����
    m_writeBuf->appendPackage(data);
}

void TcpConnection::addWriteTask(std::string data) {
    //������д��д������
    m_writeBuf->appendPackage(data);
#if 0//ͨ���¼����з���
    // 1. ���ټ��д�¼� -- �޸�channel�б�����¼�
    m_channel->setCurrentEvent(FDEvent::WriteEvent);
    // 2. �޸�dispatcher���ļ��� -- �������ڵ�
    m_evLoop->addTask(m_channel, ElemType::MODIFY);
    Debug("���ݷ������....................");
#else //ֱ�ӷ���   (���������Ƽ�������)
    m_writeBuf->sendData(m_channel->getSocket());
#endif
}

void TcpConnection::addDeleteTask() {
    m_evLoop->addTask(m_channel, ElemType::DELETE);
    Debug("�Ͽ��˺Ϳͻ��˵����ӣ�connName=%s",m_name.data());
}

