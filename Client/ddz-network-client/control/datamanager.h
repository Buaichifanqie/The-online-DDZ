#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QByteArray>
#include "communication.h"

//用饿汉模式-没有多线程的安全的问题并且简单

class DataManager
{
public:
    //禁止使用拷贝构造函数
    DataManager(const DataManager&)=delete;
    //禁止赋值运算
    DataManager& operator=(const DataManager&)=delete;

    static DataManager* getInstance();

    //设置数据
    void setUserName(QByteArray name);
    void setIP(QByteArray ip);
    void setPort(QByteArray port);
    void setCommuncation(Communication* comm);
    //获取数据
    QByteArray getUserName();
    QByteArray getIP();
    QByteArray getPort();
    Communication* getCommunication();
private:
    DataManager()=default;//私有的 并且拥有默认函数的行为
    static DataManager* m_data;

    //下面三个属于类里的唯一单例
    QByteArray m_userName;
    QByteArray m_ip="192.168.28.128";
    QByteArray m_port="9999";
    Communication* m_commun;//不能让他拷贝 所以必须用指针
};

#endif // DATAMANAGER_H
