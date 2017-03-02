#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QtNetwork/QTcpSocket>
#include "listener.h"
#include "QTimer"
#include <QtSql/QSqlDatabase>
#include <QDebug>
namespace Ui {
class ServerDialog;
}

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerDialog(QWidget *parent = 0, QTcpSocket *receiver = 0);
    explicit ServerDialog(QWidget *parent, QString ip = "127.0.0.1", quint16 port = 5000);
    ~ServerDialog();
    QHostAddress getPeerAddr();    //获得对方ip

private slots:
    void showMessage();            //在conversation中显示接收到的消息
    void sendMessage(QString final);            //发送消息
    void closeConnect();           //断开链接
    void showDisconnected();       //完成断开链接操作
    void showConnected();          //完成链接操作
    void notOline();               //对方不在线

    void on_pushButton_clicked();

private:
    Ui::ServerDialog *ui;
    QTcpSocket *receiver = Q_NULLPTR;
    QString messages = "";
    QString peerAddr = "";
    QTimer *timer;

    bool connectiondatabes();//连接数据库
    void DataInsertion();//插入数据库
    bool DataSearch(QString str);//数据查询

};
#endif // SERVERDIALOG_H
