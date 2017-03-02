#include "logdialog.h"
#include "ui_logdialog.h"
#include "QString"
#include "QLineEdit"
#include "QtNetwork/QHostInfo"
#include "QSysInfo"
#include "QFile"
#include "QByteArray"
#include "QObject"
#include "QtNetwork/QTcpSocket"
#include "QFileInfo"
#include "QTextStream"
#include "QDataStream"
#include "iostream"
#include <QMessageBox>
#include "ui_logdialog.h"
#include "qtextcodec.h"
#include "dialog.h"

extern Server server;
extern QList<QString> ipList;
extern quint16 tcpPort;
extern quint16 sendPort;

QString Username;
QString IP;
ServerDialog *oneServer;

LogDialog::LogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogDialog)
{
    ui->setupUi(this);

    ui->PasswordlineEdit->setEchoMode(QLineEdit::Password);//密码方式显示文本

    sender = new Sender();
    timer = new QTimer(this);
    timer->setSingleShot(false);

    //QHostInfo info = QHostInfo::fromName("qt-project.org");
    QString info;
    //info= QHostInfo::localHostName();
    info=QSysInfo::machineHostName();
    ui->devicelineEdit->setText(info);

    connect(&server, SIGNAL(newConnection()), this, SLOT(beConnected()));
    //connect(receiver, SIGNAL(disconnected()), this, SLOT(showDisconnected()));
    connect(this, SIGNAL(closed()), this, SLOT(closeConnect()));
    connect(sender, SIGNAL(disconnected()), this, SLOT(showDisConnected()));
    //connect(sender, SIGNAL(connected()), this, SLOT(showConnected()));
    connect(sender, SIGNAL(readyRead()), this, SLOT(showMessage()));
}

LogDialog::~LogDialog()
{
    delete ui;
}

QHostAddress LogDialog::getPeerAddr()
{
    QHostAddress addr;
    addr = sender->getPeerAddr();
    return addr;
}

void LogDialog::on_ConnectpushButton_clicked()
{
    setComunication();

    Username=ui->UserNamelineEdit->text();
    IP=ui->iplineEdit->text();
    QString Password=ui->PasswordlineEdit->text();
    sender->sendMessage(Username+"+"+Password);
}

void LogDialog::on_exitButton_clicked()
{
    close();

    Dialog z;
    z.show();
    z.exec();
    this->close();
}

void LogDialog::on_LoginButton_clicked()
{
    closeConnect();
    close();
    Dialog q;
    q.show();
    q.exec();
}

void LogDialog::setComunication()
{
    QString ip = ui->iplineEdit->text();
    quint16 port = ui->PortEdit->text().toInt();

        endSetting(port);



        if(isMulticastIp(ip)) //组播udp
        {
            if(!ipList.contains(ip))
            {
                /*isMulticast = true;
            sendPort = ui->portLine->text().toInt();
            QString label = QString::fromLocal8Bit("组播");
            ui->isMulticast->setText(label);
            MulticastDialog *groupDialog = new MulticastDialog(this, ip);

            groupDialog->show();
            ipList.append(ip);
            groupDialogList.append(groupDialog);*/
            }
        }
        else if(!Connected)  //创建链接tcp
        {
            //ui->isMulticast->setText("");
            timer->start(1000);
            sender->connectToServer(ip, port);
            peerAddr = ip;
            //ui->conversation->setText("connecting...");
            ipList.append(ip);
        }
        else if(!ipList.contains(ip)){ //主动创建新tcp链接
            //ui->isMulticast->setText("");
            ServerDialog *oneServer = new ServerDialog(this, ip, port);
            oneServer->show();
            ipList.append(ip);
            dialogList.append(oneServer);
        }

}

bool LogDialog::isMulticastIp(QString ip)
{
    QHostAddress addr(ip);
    QHostAddress begin("224.0.0.0");
    QHostAddress end("239.255.255.255");
    uint address = addr.toIPv4Address();
    uint beginAddr = begin.toIPv4Address();
    uint endAddr = end.toIPv4Address();
    if(address > beginAddr && address < endAddr)
        return true;
    return false;
}

void LogDialog::showConnected()
{
    QString statement = "";
    timer->stop();
    this->Connected = true;
    statement += peerAddr;
    QMessageBox file;
    file.setText("Already conected to: "+statement);
    file.exec();
}

void LogDialog::beConnected()
{
    receiver = server.nextPendingConnection();
    {
        ServerDialog *oneServer = new ServerDialog(this, receiver);
        oneServer->show();
        dialogList.append(oneServer);
    }
}

void LogDialog::endSetting(quint16 tcpPort)
{
    if(!isServerStart)
    {
        server.startServer(tcpPort);
        isServerStart = true;
    }
}
//关闭

void LogDialog::closeConnect()
{

    ipList.removeAll(peerAddr);
    receiver->close();
}

void LogDialog::showDisConnected()
{
    messages += QString::fromLocal8Bit("对方已断开链接");
    ipList.removeAll(peerAddr);
    QMessageBox file;
    file.setText(messages.toLocal8Bit());
    file.exec();
    messages = "";
    peerAddr = "";
}

void LogDialog::showMessage()
{
    QByteArray receiveMessage = sender->readAll();
    QDataStream out(&receiveMessage, QIODevice::ReadOnly);
    //QString recentMessage = "";
    QString recentMessage;
    QString qwe="trueuser";
    out >> recentMessage;
    //messages += peerAddr + " : " + recentMessage;
    //ui->conversation->setText(messages);
    if(recentMessage==qwe)
    {
        ui->LoginButton->setEnabled(true);
    }
    else {
        QMessageBox file;
        file.setText("fuck");
        file.exec();
    }
}
