#include "robotgraplord.h"
#include<Qthread>

RobotGrapLord::RobotGrapLord(Player* player, QObject *parent) : QObject(parent),QRunnable()
{
    m_player = player;
    //设置自动销毁
    setAutoDelete(true);
}

void RobotGrapLord::run()
{
    QThread::msleep(2000);
    m_player->thinkCallLord();
}
