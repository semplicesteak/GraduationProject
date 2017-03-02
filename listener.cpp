#include "listener.h"
#include "QDebug"

Server::Server(QObject *)
{
    setMaxPendingConnections(30);
}

Server::~Server()
{

}

void Server::startServer(quint16 tcpPort)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(print()));
    if(!this->listen(QHostAddress::Any, tcpPort))
        qDebug() << "failed to start server!";
    if(this->isListening())
        qDebug() << "is listening!";

}

void Server::print()
{
    qDebug() << "Server connected!";
}
