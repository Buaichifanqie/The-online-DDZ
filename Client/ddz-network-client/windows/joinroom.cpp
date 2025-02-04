#include "joinroom.h"
#include "datamanager.h"
#include "ui_joinroom.h"

#include <codec.h>
// #include <QString>
JoinRoom::JoinRoom(DialogType type,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::JoinRoom)
{
    ui->setupUi(this);

    const QString titles[]={
        "请输入要创建的房间的名字:",
        "请输入要搜索的房间的名字:"
    };
    int index=static_cast<int>(type);
    ui->describe->setText(titles[index]);
    ui->stackedWidget->setCurrentIndex(index);
    setFixedSize(300,180);

    connect(ui->createRoom,&QPushButton::clicked,this,&JoinRoom::joinRoom);
    connect(ui->searchRoom,&QPushButton::clicked,this,&JoinRoom::searchRoom);
    connect(ui->joinRoom,&QPushButton::clicked,this,&JoinRoom::joinRoom);
}

JoinRoom::~JoinRoom()
{
    delete ui;
}

void JoinRoom::searchRoom()
{
    encodeMessage(RequestCode::SearchRoom);
}

void JoinRoom::joinRoom()
{
    encodeMessage(RequestCode::ManualRoom);
}

void JoinRoom::encodeMessage(RequestCode code)
{
    Message msg;
    msg.reqcode=code;
    msg.userName=DataManager::getInstance()->getUserName();
    msg.roomName=ui->roomName->text().toUtf8();
    DataManager::getInstance()->getCommunication()->sendMessage(&msg);
}
