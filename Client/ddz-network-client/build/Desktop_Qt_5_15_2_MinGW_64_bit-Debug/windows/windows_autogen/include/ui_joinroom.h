/********************************************************************************
** Form generated from reading UI file 'joinroom.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINROOM_H
#define UI_JOINROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JoinRoom
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *describe;
    QLineEdit *roomName;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *createRoom;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *searchRoom;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *joinRoom;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *JoinRoom)
    {
        if (JoinRoom->objectName().isEmpty())
            JoinRoom->setObjectName(QString::fromUtf8("JoinRoom"));
        JoinRoom->resize(326, 165);
        verticalLayout = new QVBoxLayout(JoinRoom);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        describe = new QLabel(JoinRoom);
        describe->setObjectName(QString::fromUtf8("describe"));

        verticalLayout->addWidget(describe);

        roomName = new QLineEdit(JoinRoom);
        roomName->setObjectName(QString::fromUtf8("roomName"));

        verticalLayout->addWidget(roomName);

        stackedWidget = new QStackedWidget(JoinRoom);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        createRoom = new QPushButton(page);
        createRoom->setObjectName(QString::fromUtf8("createRoom"));

        horizontalLayout->addWidget(createRoom);

        horizontalSpacer_2 = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_2 = new QHBoxLayout(page_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        searchRoom = new QPushButton(page_2);
        searchRoom->setObjectName(QString::fromUtf8("searchRoom"));

        horizontalLayout_2->addWidget(searchRoom);

        horizontalSpacer_4 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        joinRoom = new QPushButton(page_2);
        joinRoom->setObjectName(QString::fromUtf8("joinRoom"));

        horizontalLayout_2->addWidget(joinRoom);

        horizontalSpacer_5 = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(JoinRoom);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(JoinRoom);
    } // setupUi

    void retranslateUi(QDialog *JoinRoom)
    {
        JoinRoom->setWindowTitle(QCoreApplication::translate("JoinRoom", "Dialog", nullptr));
        describe->setText(QCoreApplication::translate("JoinRoom", "TextLabel", nullptr));
        createRoom->setText(QCoreApplication::translate("JoinRoom", "\345\210\233\345\273\272\346\210\277\351\227\264", nullptr));
        searchRoom->setText(QCoreApplication::translate("JoinRoom", "\346\220\234\347\264\242\346\210\277\351\227\264", nullptr));
        joinRoom->setText(QCoreApplication::translate("JoinRoom", "\345\212\240\345\205\245\346\210\277\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JoinRoom: public Ui_JoinRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINROOM_H
