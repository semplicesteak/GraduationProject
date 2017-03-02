#ifndef LOGDIALOG_H
#define LOGDIALOG_H

#include <QDialog>
#include <QtNetwork/QTcpServer>
#include "sender.h"
#include "listener.h"
#include "serverdialog.h"
#include "QTimer"

namespace Ui {
class LogDialog;
}

class LogDialog : public QDialog
{
    Q_OBJECT


public:
    explicit LogDialog(QWidget *parent = 0);
    ~LogDialog();



    QHostAddress getPeerAddr();  //获得目标地址
    bool isMulticastIp(QString ip);          //判断输入的地址是否是组播地址



private slots:

    
    void on_exitButton_clicked();

    void on_LoginButton_clicked();

    void setComunication();      //建立链接
    //void sendMessage();          //发送消息
    void showConnected();        //完成链接操作
    void showDisConnected();     //完成断开链接操作
    void showMessage();          //在conversation中显示消息
    void beConnected();          //接收到别人的链接请求
    void endSetting(quint16 tcpPort);           //开启服务
    //void clearConversation();    //清屏
    //void notOnline();             //被链接对象不在线
    void closeConnect();           //断开链接



    void on_ConnectpushButton_clicked();

private:
    Ui::LogDialog *ui;



    Sender *sender = Q_NULLPTR;
    QTcpSocket *receiver = Q_NULLPTR;
    QTimer *timer = Q_NULLPTR;
    bool Connected = false;
    bool isServerStart = false;
    bool isMulticast = false;
    QString peerAddr = "";
    QString messages = "";
    QList<ServerDialog*> dialogList;

};

#endif // LOGDIALOG_H
