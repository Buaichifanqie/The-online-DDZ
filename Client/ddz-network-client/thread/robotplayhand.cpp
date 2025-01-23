#include "robotplayhand.h"
#include <QDebug>
#include <QThread>
RobotPlayHand::RobotPlayHand(Player* player, QObject *parent) : QObject(parent),QRunnable()
{
    m_player = player;
    //设置自动销毁
    setAutoDelete(true);
}

void RobotPlayHand::run()
{
    QThread::msleep(2000);
    m_player->thinkPlayHand();
}
