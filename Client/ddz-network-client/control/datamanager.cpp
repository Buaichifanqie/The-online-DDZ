#include "datamanager.h"

//必须在类的外部进行初始化
DataManager* DataManager::m_data=new DataManager;

DataManager *DataManager::getInstance()
{
    return m_data;
}

void DataManager::setUserName(QByteArray name)
{
    m_userName=name;
}

void DataManager::setIP(QByteArray ip)
{
    m_ip=ip;
}

void DataManager::setPort(QByteArray port)
{
    m_port=port;
}

void DataManager::setCommuncation(Communication *comm)
{
    m_commun=comm;
}

void DataManager::setRoomName(QByteArray roomName)
{
    m_roomName=roomName;
}

void DataManager::setCards(Cards cs, Cards last)
{
    m_cs=cs;
    m_last=last;
}

void DataManager::setGameMode(GameMode mode)
{
    m_mode=mode;
}

QByteArray DataManager::getUserName()
{
    return m_userName;
}

QByteArray DataManager::getRoomName()
{
    return m_roomName;
}

QByteArray DataManager::getIP()
{
    return m_ip;
}

QByteArray DataManager::getPort()
{
    return m_port;
}

Communication *DataManager::getCommunication()
{
    return m_commun;
}

Cards DataManager::getCards()
{
    return m_cs;
}

Cards DataManager::getLast3Cards()
{
    return m_last;
}

DataManager::GameMode DataManager::getGameMode()
{
    return m_mode;
}



