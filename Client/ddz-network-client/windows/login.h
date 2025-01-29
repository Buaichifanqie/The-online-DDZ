#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>
#include "codec.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    //校验数据函数
    bool verifyData(QLineEdit* edit);
    //连接服务器
    void startConnect(Message* msg);
    //槽函数
    void onLogin();
    void onRegister();
    void onNetOK();
    ~Login();

private:
    Ui::Login *ui;
    bool m_isConnected=false;
};

#endif // LOGIN_H
