#include "login.h"
#include "datamanager.h"
#include "ui_login.h"
#include "gamepanel.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <qthreadpool.h>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->homeBtn,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->regUser,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->netsetBtn,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //数据校验
    QRegularExpression expreg("^[a-zA-Z0-9_]{3,16}$");

    //需要是堆内存 如果是局部对象函数走完就析构了
    // 如果被析构了 因为校验时需要规则 而规则是再val1里的 此时就拿不到正则表达式了
    //所以必须弄成一个指针
    QRegularExpressionValidator *val1=new QRegularExpressionValidator(expreg,this);
    //设置给文本编辑框         使用父类指针指向子类对象（多态）
    //登陆时用户名
    ui->userName->setValidator(val1);
    //注册时用户名
    ui->regUserName->setValidator(val1);
    //密码
    expreg.setPattern("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{4,20}$");
    QRegularExpressionValidator *val2=new QRegularExpressionValidator(expreg,this);
    ui->password->setValidator(val2);
    ui->regPassword->setValidator(val2);

    //手机号校验
    expreg.setPattern("^1[3456759]\\d{9}$");
    QRegularExpressionValidator *val3=new QRegularExpressionValidator(expreg,this);
    ui->phone->setValidator(val3);

    //ip校验
    expreg.setPattern("^((\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){3}(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])$");
    QRegularExpressionValidator *val4=new QRegularExpressionValidator(expreg,this);
    ui->ipAddr->setValidator(val4);

    //端口号校验
    expreg.setPattern("^(0|([1-9]\\d{0,3})|([1-5]\\d{4})|(6[0-4]\\d{3})|(65[0-4]\\d{2})|(655[0-2]\\d)|(6553[0-5]))$");
    QRegularExpressionValidator *val5=new QRegularExpressionValidator(expreg,this);
    ui->port->setValidator(val5);

    //处理按钮点击事件
    connect(ui->loginBtn,&QPushButton::clicked,this,&Login::onLogin);
    connect(ui->registerBtn,&QPushButton::clicked,this,&Login::onRegister);
    connect(ui->netOkBtn,&QPushButton::clicked,this,&Login::onNetOK);

    //设置线程池最大线程数量
    QThreadPool::globalInstance()->setMaxThreadCount(8);

}

// 验证输入框数据的有效性
bool Login::verifyData(QLineEdit* edit)
{
    // 如果输入框中的数据无效（不符合设定的输入规则）
    if(edit->hasAcceptableInput() == false)
    {
        // 设置输入框的边框为红色，表示输入无效
        edit->setStyleSheet("border: 2px solid red;");
        return false; // 返回 false，表示数据无效
    }
    else
    {
        // 如果输入有效，重置输入框样式
        edit->setStyleSheet("none");
    }
    return true; // 返回 true，表示数据有效
}

void Login::onLogin()
{
    bool flag1=verifyData(ui->userName);
    bool flag2=verifyData(ui->password);
    if(flag1&&flag2)
    {
        GamePanel* panel=new GamePanel;
        panel->show();
    }
}

void Login::onRegister()
{
    bool flag1=verifyData(ui->regUserName);
    bool flag2=verifyData(ui->regPassword);
    bool flag3=verifyData(ui->phone);
    if(flag1 && flag2 && flag3)
    {

    }
}

void Login::onNetOK()
{
    bool flag1=verifyData(ui->ipAddr);
    bool flag2=verifyData(ui->port);
    if(flag1&&flag2)
    {
        //得到一个实例对象
        DataManager* instance=DataManager::getInstance();
        //将ip和端口存储起来
        instance->setIP(ui->ipAddr->text().toUtf8());//从Qstring->QByteArray
        instance->setPort(ui->port->text().toUtf8());
    }
}

Login::~Login()
{
    delete ui;
}
