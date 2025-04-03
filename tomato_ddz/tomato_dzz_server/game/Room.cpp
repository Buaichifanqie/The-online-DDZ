//
// Created by subingwen
//

#include <random>
#include "Room.h"
#include "JsonParse.h"
#include "Log.h"


std::string Room::rsaSecKey(std::string field)
{
    auto value = m_redis->hget("RSA", field);
    if(value.has_value())
    {
        return value.value();
    }
    return std::string();
}

void Room::clear()
{
    // flushdb
    m_redis->flushdb();
}

//bool Room::initEnvironment()
//{
//    //tcp://127.0.0.1:6379
//    JsonParse json;
//    auto info = json.getDatabaseInfo(JsonParse::Redis);
//    std::string connStr = "tcp://" + info->ip + ":" + std::to_string(info->port);
//    m_redis = new sw::redis::Redis(connStr);
//    // 测试连接
//    if(m_redis->ping() == "PONG")
//    {
//        Debug("成功连接了 redis 服务器...");
//        return true;
//    }
//    return false;
//}

//bool Room::initEnvironment()
//{
//    JsonParse json;
//    auto info = json.getDatabaseInfo(JsonParse::Redis);
//    try {
//        sw::redis::ConnectionOptions opts;
//        opts.host = info->ip;       // 直接赋值IP
//        opts.port = info->port;     // 直接赋值端口
//        opts.password = info->passwd; // 单独设置密码字段
//        opts.socket_timeout = std::chrono::milliseconds(2000);
//
//
//        sw::redis::ConnectionPoolOptions pool_opts;
//        pool_opts.size = 3;
//
//        m_redis = new sw::redis::Redis(opts, pool_opts);
//
//        // 测试连接
//        m_redis->ping();
//        Debug("Redis连接成功");
//        return true;
//    } catch (const sw::redis::Error &e) {
//        Debug("Redis连接异常: %s", e.what());
//    }
//    return false;
//}

bool Room::initEnvironment() {
    JsonParse json;
    auto info = json.getDatabaseInfo(JsonParse::Redis);
    Debug("Redis密码: %s", info->passwd.c_str()); // 如果输出为空，说明解析失败
    try {
        Debug("尝试连接 Redis: IP=%s, Port=%d, Password=%s",
              info->ip.c_str(), info->port, info->passwd.empty() ? "空" : "已设置");

        sw::redis::ConnectionOptions opts;
        opts.host = info->ip;
        opts.port = info->port;
        opts.password = info->passwd;
        opts.socket_timeout = std::chrono::milliseconds(2000);

        sw::redis::ConnectionPoolOptions pool_opts;
        pool_opts.size = 3;

        m_redis = new sw::redis::Redis(opts, pool_opts);

        // 显式测试密码是否正确
        auto pong = m_redis->ping();
        Debug("Redis Ping 响应: %s", pong.c_str());

        Debug("Redis连接成功");
        return true;
    } catch (const sw::redis::Error &e) {
        Debug("Redis连接失败: %s", e.what());
        return false;
    }
}

Room::~Room()
{
    if(m_redis)
    {
        delete m_redis;
    }
}

void Room::saveRsaSecKey(std::string field, std::string value)
{
    m_redis->hset("RSA", field, value);
}

std::string Room::joinRoom(std::string userName)
{
    std::optional<std::string> room;
    do{
        // scard
        if(m_redis->scard(TwoPlayer) > 0)
        {
            // srandmember
            room = m_redis->srandmember(TwoPlayer);
            break;
        }
        if(m_redis->scard(OnePlayer) > 0)
        {
            // srandmember
            room = m_redis->srandmember(OnePlayer);
            break;
        }
        // 添加新的房间
        room = getNewRoomName();
    }while(0);
    // 加入到某个房间中
    joinRoom(userName, room.value());
    return room.value();
}

std::string Room::getNewRoomName()
{
    // 创建随机设备对象
    std::random_device rd;
    // 创建随机数生成对象
    std::mt19937 gen(rd());
    // 创建随机数分布对象 -> 均匀分布
    std::uniform_int_distribution<int> dis(100000, 999999);
    int randNum = dis(gen);
    return std::to_string(randNum);
}

bool Room::joinRoom(std::string userName, std::string roomName)
{
    if(m_redis->zcard(roomName) >= 3)
    {
        return false;
    }
    // 检查房间是否存在
    if(!m_redis->exists(roomName))
    {
        m_redis->sadd(OnePlayer, roomName);
    }
    // 移动房间
    else if(m_redis->sismember(OnePlayer, roomName))
    {
        m_redis->smove(OnePlayer, TwoPlayer, roomName);
    }
    else if(m_redis->sismember(TwoPlayer, roomName))
    {
        m_redis->smove(TwoPlayer, ThreePlayer, roomName);
    }
    else
    {
        assert(false);  // 异常情况, 直接退出
    }
    // 将玩家添加到房间, 使用的结构是 sortedset
    m_redis->zadd(roomName, userName, 0);
    // 将玩家存储起来 hashs -> 通过玩家找到玩家的房间
    m_redis->hset("Players", userName, roomName);
    return true;
}

int Room::getPlayerCount(std::string roomName)
{
    int count = m_redis->zcard(roomName);
    return count;
}

void Room::updatePlayerScore(std::string roomName, std::string userName, int score)
{
    // 更新 -> sortedset
    m_redis->zadd(roomName, userName, score);
}

std::string Room::whereAmI(std::string userName)
{
    auto value = m_redis->hget("Players", userName);
    if(value.has_value())
    {
        return value.value();
    }
    return std::string();
}

int Room::playerScore(std::string roomName, std::string userName)
{
    auto score = m_redis->zscore(roomName, userName);
    if(score.has_value())
    {
        return score.value();
    }
    return 0;
}

std::string Room::playersOrder(std::string roomName)
{
    int index = 0;
    std::string data;
    std::vector<std::pair<std::string, double>> output;
    // 对房间中的玩家进行排序, 降序排序zrevrange
    m_redis->zrevrange(roomName, 0, -1, std::back_inserter(output));
    for(auto& it : output)
    {
        data += it.first + "-" + std::to_string(++index) + "-" + std::to_string((int)it.second) + "#";
    }
    return data;
}

void Room::leaveRoom(std::string roomName, std::string userName)
{
    if(m_redis->sismember(ThreePlayer, roomName))
    {
        m_redis->smove(ThreePlayer, Invalid, roomName);
    }
    // 从房间中删除玩家
    m_redis->zrem(roomName, userName);
    auto count = m_redis->zcard(roomName);
    if(count == 0)
    {
        m_redis->del(roomName);
        m_redis->srem(Invalid, roomName);
    }
}

bool Room::searchRoom(std::string roomName)
{
    // 搜索二人间
    bool flag = m_redis->sismember(TwoPlayer, roomName);
    // 搜索一人间
    if(!flag)
    {
        flag = m_redis->sismember(OnePlayer, roomName);
    }
    return flag;
}
