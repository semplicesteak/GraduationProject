#ifndef LISTENER_H
#define LISTENER_H
//#include <QTcpServer>
#include <QtNetwork/QTcpServer>

class Server:public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = 0);
    ~Server();
    void startServer(quint16 tcpPort = 5000);

private slots:
    void print();
};
#endif // LISTENER_H

