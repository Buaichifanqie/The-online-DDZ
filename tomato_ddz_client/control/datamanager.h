#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QByteArray>
#include "cards.h"
#include "communication.h"

// 饿汉模式
class DataManager
{
public:
    enum GameMode{Single, Network};
    enum RoomMode{Auto, Manual};
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;
    static DataManager* getInstance();

    // 设置数据
    void setUserName(QByteArray name);
    void setIP(QByteArray ip);
    void setPort(QByteArray port);
    void setCommunication(Communication* comm);
    void setRoomName(QByteArray roomName);
    void setCards(Cards cs, Cards last);
    void setGameMode(GameMode mode);
    void setRoomMode(RoomMode mode);
    // 获取数据
    QByteArray getUserName();
    QByteArray getIP();
    QByteArray getPort();
    QByteArray getRoomName();
    Communication* getCommunication();
    Cards getCards();
    Cards getLast3Cards();
    bool isNetworkMode();
    bool isManualMode();
private:
    DataManager() = default;
    static DataManager* m_data;

    QByteArray m_userName;
    QByteArray m_roomName;
	// 修改成自己web服务器的IP地址
    QByteArray m_ip = "192.168.28.129";
	// 修改成自己web服务器的端口
    QByteArray m_port = "9999";
    Communication* m_commun;
    Cards m_cs;
    Cards m_last;
    GameMode m_mode;
    RoomMode m_roomMode;
};

#endif // DATAMANAGER_H
