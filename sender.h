#ifndef SENDER_H
#define SENDER_H
//#include <QTcpSocket>
#include <QtNetwork/QTcpSocket>
//#include <qhostaddress.h>
#include <QtNetwork/qhostaddress.h>

class Sender:public QTcpSocket
{
    Q_OBJECT

public:
    Sender(QObject *parent = 0);
    ~Sender();
    QHostAddress getPeerAddr();                         //获得对方ip
    void sendMessage(QString message);                  //发送消息
    void connectToServer(QString ip, quint16 port);     //创建链接

private slots:
    void closeConnect();                                //断开链接

};
#endif // SENDER_H

