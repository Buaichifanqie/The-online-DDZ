//
// Created by kongwenshuo on 25-1-30.
//

#ifndef SERVER_ROOM_H
#define SERVER_ROOM_H
#include <string>
#include "redis++.h"
#include <vector>
//using namespace sw::redis;

class Room {
public:
    Room()=default;
    ~Room();

    //初始化-连接redis,redis++
    bool initEnvironment();

    //清空数据
    void clear();
    //保存RSA密钥对
    void saveRsaSecKey(std::string filed,std::string value);
    //读密钥
    std::string rsaSecKey(std::string filed);
    //加入房间函数
    std::string joinRoom(std::string userName);
    bool joinRoom(std::string userName,std::string roomName);
    //随机生成房间名
    std::string getNewRoomName();
    //得到房间人数
    int getPlayerCount(std::string roomName);
    //存储玩家的分数
    void updatePlayerScore(std::string roomName,std::string userName,int score);
    //通过玩家名字找房间
    std::string WhereAmI(std::string userName);
    //查询分数
    int playerScore(std::string roomName,std::string userName);
    //得到抢地主的次序
    std::string playersOder(std::string roomName);
private:
    sw::redis::Redis* m_redis;
    const std::string OnePlayer="OnePlayer";
    const std::string TwoPlayer="TwoPlayer";
    const std::string ThreePlayer="ThreePlayer";
};


#endif //SERVER_ROOM_H
