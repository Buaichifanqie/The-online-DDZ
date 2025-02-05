#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QRunnable>
#include "tcpsocket.h"
#include "codec.h"
#include "aescrypto.h"

class Communication : public QObject,public QRunnable
{
    Q_OBJECT
public:
    enum KeyLen{
        L16=16,
        L24=24,
        L32=32
    };

    explicit Communication(Message& msg,QObject *parent = nullptr);
    ~Communication();
    inline void stopLoop()
    {
        m_stop=true;
    }
    //给服务器发送数据
    void sendMessage(Message* msg,bool encrypt=true);
    //解析数据-服务器发过来的数据
    void parseRecvMessage();
    //密钥分发
    void handleRsaFenfa(Message* msg);
    //生成密钥函数aes
    QByteArray generateAseKey(KeyLen len);
    //解析扑克牌信息
    void parseCards(QByteArray data1,QByteArray data2);


protected:
    void run() override;

signals:
    void connectFailed();
    void loginOk();
    void registerOk();
    void failedMsg(QByteArray msg);
    void playerCount(int number);
    void startGame(QByteArray msg);
private:
    Message m_msgInfo;
    bool m_stop=false;
    Tcpsocket* m_socket=nullptr;
    QByteArray m_aesKey;
    AesCrypto* m_aes=nullptr;
};

#endif // COMMUNICATION_H
