//
// Created by kongwenshuo on 25-2-1.
//

#ifndef SERVER_ROOMLIST_H
#define SERVER_ROOMLIST_H
#include <map>
#include <string>
#include <functional>
#include <mutex>
//单例模式类 懒汉模式
using callback=std::function<void(std::string)>;
using UserMap=std::map<std::string,callback>;
class RoomList {
public:
    RoomList(const RoomList& ) =delete;//禁止拷贝
    RoomList& operator = (const RoomList&)=delete;//禁止赋值
    static RoomList* getInstance();
    //添加用户
    void addUser(std::string roomName,std::string userName,callback sendMessage);
    //通过房间名字获取成员信息
    UserMap getPlayers(std::string roomName);
private:
    RoomList()=default;
    std::map<std::string,UserMap>m_roomMap;//共享资源，需要多线程访问
    std::mutex m_mutex;
};


#endif //SERVER_ROOMLIST_H
