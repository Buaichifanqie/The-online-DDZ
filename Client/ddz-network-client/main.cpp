#include "cards.h"
#include "login.h"

#include <QApplication>
#include <QResource>
#include "aescrypto.h"
#include <QDebug>

void test()
{
    AesCrypto aes(AesCrypto::AES_CBC_128,"1234567887654321");
    QByteArray text=aes.encrypt("奥奇传说启动!!!");
    text=aes.decrypt(text);
    qDebug()<<text.data();
}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qRegisterMetaType<Cards>("Cards&");
    qRegisterMetaType<Cards>("Cards");
    //QResource::registerResource("./resource.rcc");
    Login w;
    w.show();
    test();

    return a.exec();
}
