#include "gamemode.h"
#include "ui_gamemode.h"

#include "gamepanel.h"
#include "joinroom.h"

#include "datamanager.h"
#include <QCloseEvent>
#include <codec.h>

GameMode::GameMode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameMode)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->information->setVisible(false);

    //取出通信类的实例对象
    Communication* comm= DataManager::getInstance()->getCommunication();
    connect(comm,&Communication::playerCount,this,[=](int count){
        QString tip=QString("当前<%1>房间玩家的人数为%2人,正在等待其他玩家进入,请稍后")
            .arg(DataManager::getInstance()->getRoomName().data())
            .arg(count);
        ui->information->setText(tip);
        ui->information->setVisible(true);
    });

    //开始游戏
    connect(comm,&Communication::startGame,this,[=](QByteArray msg)
    {
        this->hide();
        GamePanel* panel=new GamePanel;
        connect(panel,&GamePanel::panelClose,this,&GameMode::show);
        panel->show();
        //初始化数据
        panel->initGamePanel(msg);
        //断开信号槽连接
        disconnect(comm,&Communication::startGame,this,nullptr);
    });

    connect(ui->stackedWidget,&QStackedWidget::currentChanged,this,[=](int index){
        if(index==0){
            ui->information->setVisible(false);
        }
    });

    connect(ui->singleModeBtn,&QPushButton::clicked,this,[=](){
        GamePanel* panel=new GamePanel;
        connect(panel,&GamePanel::panelClose,this,&GameMode::show);
        panel->show();
        hide();
        DataManager::getInstance()->setGameMode(DataManager::Single);
    });

    connect(ui->netModeBtn,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
        DataManager::getInstance()->setGameMode(DataManager::NetWork);
    });

    //自动加入到某个房间
    connect(ui->autoBtn,&QPushButton::clicked,this,[=](){
        Message msg;
        msg.userName=DataManager::getInstance()->getUserName();
        msg.reqcode=RequestCode::AutoRoom;
        DataManager::getInstance()->getCommunication()->sendMessage(&msg);
    });

    connect(ui->manualBtn,&QPushButton::clicked,this,[=](){
        JoinRoom room(DialogType::Manual);
        room.setWindowTitle("创建房间");
        room.exec();
    });
    connect(ui->searchBtn,&QPushButton::clicked,this,[=](){
        JoinRoom room(DialogType::Search);
        room.setWindowTitle("搜索房间");
        room.exec();
    });
}

GameMode::~GameMode()
{
    delete ui;
}

void GameMode::closeEvent(QCloseEvent *ev)
{
    if(ui->stackedWidget->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(0);
        ev->ignore();
    }
    else
    {
        ev->accept();
    }
}
