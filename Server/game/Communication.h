//
// Created by subingwen
//

#ifndef SERVER_DDZ_COMMUNICATION_H
#define SERVER_DDZ_COMMUNICATION_H
#include "Buffer.h"
#include "Codec.h"
#include "AesCrypto.h"
#include "MySqlConn.h"

#include <functional>

class Communication
{
public:
    Communication();

    // 解析客户端发送过来的数据
    void parseRequest(Buffer* buf);
    // 设置回调
    using sendCallback = function<void(std::string)>;
    using deleteCallback = function<void()>;
    void setCallback(sendCallback func1, deleteCallback fucn2);
    // 处理秘钥分发
    void handleAesFenfa(Message* reqMsg, Message& resMsg);
    void handleRegister(Message* reqMsg, Message& resMsg);
    void handleLogin(Message* reqMsg, Message& resMsg);

private:
    sendCallback sendMessage;
    deleteCallback disconnect;
    AesCrypto* m_aes = nullptr;
    MySqlConn *m_mysql = nullptr;

};


#endif //SERVER_DDZ_COMMUNICATION_H
