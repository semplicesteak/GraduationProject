#include "sender.h"
#include "QDebug"
#include "QDataStream"

Sender::Sender(QObject *)
{

}

Sender::~Sender()
{

}

void Sender::connectToServer(QString ip, quint16 port)
{
    const QString addr = ip;
    const QHostAddress address = QHostAddress(addr);

    this->connectToHost(address, port, QTcpSocket::ReadWrite);
}

void Sender::closeConnect()
{
    this->close();
}

QHostAddress Sender::getPeerAddr()
{
    return peerAddress();
}

void Sender::sendMessage(QString message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    out << message;
    this->write(block);
}
