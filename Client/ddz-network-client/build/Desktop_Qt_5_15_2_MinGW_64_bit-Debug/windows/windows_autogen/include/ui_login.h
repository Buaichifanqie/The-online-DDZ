/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *yonghuming;
    QLineEdit *userName;
    QLabel *mima;
    QLineEdit *password;
    QCheckBox *savePwd;
    QPushButton *regUser;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_6;
    QGridLayout *gridLayout_2;
    QLabel *yonghuming2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *registerBtn;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *regPassword;
    QLineEdit *regUserName;
    QLabel *shoujihao;
    QLabel *mima2;
    QLineEdit *phone;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_9;
    QGridLayout *gridLayout_3;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *netOkBtn;
    QSpacerItem *horizontalSpacer_12;
    QLabel *ipdizhi;
    QLabel *duankouhao;
    QLineEdit *port;
    QLineEdit *ipAddr;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_6;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *homeBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *netsetBtn;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(715, 492);
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 145, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        yonghuming = new QLabel(widget);
        yonghuming->setObjectName(QString::fromUtf8("yonghuming"));

        gridLayout->addWidget(yonghuming, 0, 0, 1, 1);

        userName = new QLineEdit(widget);
        userName->setObjectName(QString::fromUtf8("userName"));

        gridLayout->addWidget(userName, 0, 1, 1, 2);

        mima = new QLabel(widget);
        mima->setObjectName(QString::fromUtf8("mima"));

        gridLayout->addWidget(mima, 1, 0, 1, 1);

        password = new QLineEdit(widget);
        password->setObjectName(QString::fromUtf8("password"));

        gridLayout->addWidget(password, 1, 1, 1, 2);

        savePwd = new QCheckBox(widget);
        savePwd->setObjectName(QString::fromUtf8("savePwd"));

        gridLayout->addWidget(savePwd, 2, 0, 1, 2);

        regUser = new QPushButton(widget);
        regUser->setObjectName(QString::fromUtf8("regUser"));

        gridLayout->addWidget(regUser, 2, 2, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loginBtn = new QPushButton(widget_2);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));

        horizontalLayout->addWidget(loginBtn);

        horizontalSpacer_2 = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget_2, 3, 0, 1, 3);


        horizontalLayout_2->addWidget(widget);

        horizontalSpacer_4 = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_3);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 145, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        widget_5 = new QWidget(page_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_2 = new QGridLayout(widget_6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        yonghuming2 = new QLabel(widget_6);
        yonghuming2->setObjectName(QString::fromUtf8("yonghuming2"));

        gridLayout_2->addWidget(yonghuming2, 0, 0, 1, 1);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        registerBtn = new QPushButton(widget_7);
        registerBtn->setObjectName(QString::fromUtf8("registerBtn"));

        horizontalLayout_5->addWidget(registerBtn);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        gridLayout_2->addWidget(widget_7, 3, 0, 1, 3);

        regPassword = new QLineEdit(widget_6);
        regPassword->setObjectName(QString::fromUtf8("regPassword"));

        gridLayout_2->addWidget(regPassword, 1, 1, 1, 2);

        regUserName = new QLineEdit(widget_6);
        regUserName->setObjectName(QString::fromUtf8("regUserName"));

        gridLayout_2->addWidget(regUserName, 0, 1, 1, 2);

        shoujihao = new QLabel(widget_6);
        shoujihao->setObjectName(QString::fromUtf8("shoujihao"));

        gridLayout_2->addWidget(shoujihao, 2, 0, 1, 1);

        mima2 = new QLabel(widget_6);
        mima2->setObjectName(QString::fromUtf8("mima2"));

        gridLayout_2->addWidget(mima2, 1, 0, 1, 1);

        phone = new QLineEdit(widget_6);
        phone->setObjectName(QString::fromUtf8("phone"));

        gridLayout_2->addWidget(phone, 2, 1, 1, 1);


        horizontalLayout_4->addWidget(widget_6);

        horizontalSpacer_9 = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_3->addWidget(widget_5);

        verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_4 = new QVBoxLayout(page_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 145, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_5);

        widget_8 = new QWidget(page_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        gridLayout_3 = new QGridLayout(widget_9);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_10 = new QWidget(widget_9);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_7 = new QHBoxLayout(widget_10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        netOkBtn = new QPushButton(widget_10);
        netOkBtn->setObjectName(QString::fromUtf8("netOkBtn"));

        horizontalLayout_7->addWidget(netOkBtn);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);


        gridLayout_3->addWidget(widget_10, 2, 0, 1, 3);

        ipdizhi = new QLabel(widget_9);
        ipdizhi->setObjectName(QString::fromUtf8("ipdizhi"));

        gridLayout_3->addWidget(ipdizhi, 0, 0, 1, 1);

        duankouhao = new QLabel(widget_9);
        duankouhao->setObjectName(QString::fromUtf8("duankouhao"));

        gridLayout_3->addWidget(duankouhao, 1, 0, 1, 1);

        port = new QLineEdit(widget_9);
        port->setObjectName(QString::fromUtf8("port"));

        gridLayout_3->addWidget(port, 1, 1, 1, 2);

        ipAddr = new QLineEdit(widget_9);
        ipAddr->setObjectName(QString::fromUtf8("ipAddr"));

        gridLayout_3->addWidget(ipAddr, 0, 1, 1, 2);


        horizontalLayout_6->addWidget(widget_9);

        horizontalSpacer_13 = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);


        verticalLayout_4->addWidget(widget_8);

        verticalSpacer_6 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);

        widget_4 = new QWidget(Login);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        homeBtn = new QPushButton(widget_4);
        homeBtn->setObjectName(QString::fromUtf8("homeBtn"));

        horizontalLayout_3->addWidget(homeBtn);

        horizontalSpacer_5 = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        netsetBtn = new QPushButton(widget_4);
        netsetBtn->setObjectName(QString::fromUtf8("netsetBtn"));

        horizontalLayout_3->addWidget(netsetBtn);


        verticalLayout_2->addWidget(widget_4);


        retranslateUi(Login);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        yonghuming->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", nullptr));
        mima->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        savePwd->setText(QCoreApplication::translate("Login", "\344\277\235\345\255\230\345\257\206\347\240\201", nullptr));
        regUser->setText(QCoreApplication::translate("Login", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\214\351\251\254\344\270\212\346\263\250\345\206\214", nullptr));
        loginBtn->setText(QString());
        yonghuming2->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", nullptr));
        registerBtn->setText(QString());
        shoujihao->setText(QCoreApplication::translate("Login", "\346\211\213\346\234\272\345\217\267:", nullptr));
        mima2->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201:", nullptr));
        netOkBtn->setText(QString());
        ipdizhi->setText(QCoreApplication::translate("Login", "ip\345\234\260\345\235\200\357\274\232", nullptr));
        duankouhao->setText(QCoreApplication::translate("Login", "\347\253\257\345\217\243\345\217\267:", nullptr));
        homeBtn->setText(QString());
        netsetBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
