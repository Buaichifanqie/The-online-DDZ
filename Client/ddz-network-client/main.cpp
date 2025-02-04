#include "cards.h"
#include "login.h"

#include "rsacrypto.h"
#include <QApplication>
#include <QResource>
#include "aescrypto.h"
#include <QDebug>

void test()
{
    AesCrypto aes(AesCrypto::AES_CBC_128, "1234567887654321");
    QByteArray text = aes.encrypt("奥奇传说启动！！！");
    text = aes.decrypt(text);
    qDebug() << text.data();

    RsaCrypto rsa;
    rsa.generateRsaKey(RsaCrypto::BITS_2k);

    RsaCrypto rsa1("public.pem", RsaCrypto::PublicKey);
    // 可加密的最大数据长度 = bits/8-11;  11是填充
    QByteArray temp = "我要玩奥奇传说！！！";
    temp = rsa1.pubKeyEncrypt(temp);
    qDebug() << "公钥加密的密文: " << temp;

    RsaCrypto rsa2("private.pem", RsaCrypto::PrivateKey);
    temp = rsa2.priKeyDecrypt(temp);
    qDebug() << temp.data();


    temp = rsa2.sign(text);
    qDebug() << "私钥签名的密文: " << temp;

    bool flag = rsa1.verify(temp, text);
    qDebug() << "flag = " << flag;

}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qRegisterMetaType<Cards>("Cards&");
    qRegisterMetaType<Cards>("Cards");
    //QResource::registerResource("./resource.rcc");
    Login w;
    int ret=w.exec();
    if(ret==QDialog::Accepted)
    {
        test();
        return a.exec();
    }

}
