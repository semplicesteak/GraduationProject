#include "serverdialog.h"
#include "sender.h"
#include "ui_serverdialog.h"
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>
extern QList<QString> ipList;

ServerDialog::ServerDialog(QWidget *parent, QTcpSocket *receiver) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
    this->receiver = receiver;
    ui->sendButton->setEnabled(true);
    bool isEmited = false;
    timer = new QTimer(this);
    timer->setSingleShot(false);

    if(receiver->state() == QAbstractSocket::ConnectedState)
        isEmited = true;

    connect(receiver, SIGNAL(readyRead()), this, SLOT(showMessage()));
    connect(receiver, SIGNAL(connected()), this, SLOT(showConnected()));
    connect(receiver, SIGNAL(disconnected()), this, SLOT(showDisconnected()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(this, SIGNAL(rejected()), this, SLOT(closeConnect()));
    connect(timer, SIGNAL(timeout()), this, SLOT(notOline()));

    if(isEmited)
        emit receiver->connected();

}

ServerDialog::ServerDialog(QWidget *parent, QString ip, quint16 port) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
    receiver = new QTcpSocket();
    ui->sendButton->setEnabled(true);

    connect(receiver, SIGNAL(readyRead()), this, SLOT(showMessage()));
    connect(receiver, SIGNAL(connected()), this, SLOT(showConnected()));
    connect(receiver, SIGNAL(disconnected()), this, SLOT(showDisconnected()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(this, SIGNAL(rejected()), this, SLOT(closeConnect()));

    timer->start(1000);
    ((Sender*)receiver)->connectToServer(ip, port);

}

ServerDialog::~ServerDialog()
{
    if(receiver != Q_NULLPTR)
        delete receiver;
    delete ui;
}

void ServerDialog::showMessage()
{
    QByteArray receiveMessage = receiver->readAll();
    QDataStream out(&receiveMessage, QIODevice::ReadOnly);
    QString recentMessage = "";
    QString good="trueuser";
    QString bad="falseuser";
    out >> recentMessage;
    //DataSearch(recentMessage);
    if(DataSearch(recentMessage))
    {
        sendMessage(good);
    }
    else{
        sendMessage(bad);
    }
    messages += peerAddr + " : " + recentMessage;
    ui->conversation->setText(messages);
}

void ServerDialog::sendMessage(QString final)
{
    QString message = final;
    ((Sender*)receiver)->sendMessage(message);
    messages += "Me : " + message;
    ui->conversation->setText(messages);
    ui->view->setText("");
}

void ServerDialog::closeConnect()
{
    ipList.removeAll(peerAddr);
    receiver->close();
}

QHostAddress ServerDialog::getPeerAddr()
{
    QHostAddress addr;
    addr = ((Sender*)receiver)->getPeerAddr();
    return addr;
}

void ServerDialog::showDisconnected()
{
    messages += QString::fromLocal8Bit("对方已断开链接");
    ipList.removeAll(peerAddr);
    ui->conversation->setText(messages);
    ui->sendButton->setEnabled(false);
    messages = "";
    peerAddr = "";
}

void ServerDialog::showConnected()
{
    timer->stop();
    peerAddr = getPeerAddr().toString();
    ipList.append(peerAddr);
    ui->conversation->setText("Already conected to: " + peerAddr);
    ui->ipLine->setText(peerAddr);
    ui->ipLine->setEnabled(false);
    connectiondatabes();
}

void ServerDialog::notOline()
{
    ui->conversation->setText("Not Online!");
}

void ServerDialog::on_pushButton_clicked()
{
    close();
    closeConnect();
}

bool ServerDialog::connectiondatabes()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Userdb");
    db.setUserName("root");
    db.setPassword("0422");

    if(db.open())
    {
        qDebug() << "database is established!";
        //QSqlQuery query;
        //query.exec("insert into User values(1,123,456)");

    }
    else
    {
        qDebug() << "build error!";
        return false;
    }
    //return true;
    return 0;

}

void ServerDialog::DataInsertion()
{
    QSqlQuery query;
    query.prepare("insert into     ,values(:    ,:   ,:   )");
    query.bindValue(": ",": ");//绑定插入的值
    query.bindValue(": ",": ");
    query.bindValue(": ",": ");
    query.exec();
}

bool ServerDialog::DataSearch(QString str)
{
    QSqlQuery query;
    int q=0;
    /*query.exec("select username from User where 456");
    while(query.next())
    {
        qDebug()<<query.value(0).toString();
    }*/

    //QString sqlquery;
    //sqlquery=QObject::tr("select username from user where username=%1").arg(username);
    //query.exec(QString("select username from user where username=%1").arg(username));
    query.exec("select * from user");
    QStringList list=str.split("+");
    QString username=list[0];
    QString password=list[1];
    while(query.next())
    {
        if(query.value(1).toString()==username)
        {
            if(query.value(2).toString()==password)
            {
                q=1;
                break;
            }
            else{
                break;
            }
            //q=1;
            //break;
        }
        else{
            continue;
        }
    }
    //qDebug()<<query.exec(sqlquery);
    if(q==1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
