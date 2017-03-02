#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>
#include <QtNetwork/QtNetwork>
#include <logdialog.h>
#include <QFileDialog>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sender.h>
#include <listener.h>
#include "QtNetwork/QAbstractSocket"
#include "QtNetwork/QTcpSocket"
#include <serverdialog.h>
#include <QTimer>
#include <QtNetwork/QTcpServer>

namespace Ui {
class FileDialog;
}

#define SM4_ENCRYPT     1
#define SM4_DECRYPT     0

#define PLAIN_FILE_OPEN_ERROR -1
#define KEY_FILE_OPEN_ERROR -2
#define CIPHER_FILE_OPEN_ERROR -3
#define OK 1

typedef char ElemType;

typedef struct
{
    int mode;                   /*!<  encrypt/decrypt   */
    unsigned long sk[32];       /*!<  SM4 subkeys       */
}sm4_context;

class FileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileDialog(QWidget *parent = 0);
    ~FileDialog();

        bool isMulticastIp(QString ip);          //判断输入的地址是否是组播地址
        QHostAddress getPeerAddr();  //获得目标地址

    //SM4
    void sm4_setkey_enc(sm4_context *ctx, unsigned char key[16]);

    void sm4_setkey_dec(sm4_context *ctx, unsigned char key[16]);

    void SMS4DECRYPT(char plainFile[], char str[], char cipherFile[]);

    void SMS4ENCRYPT(char* plainFile, char* str, char* cipherFile);

    int SMS4_ByteToBit(ElemType ch, ElemType bit[18]);

    int SMS4_BitToByte(ElemType bit[16], ElemType *ch);

    int SMS4_Char8ToBit64(ElemType ch[16], ElemType bit[64]);

    int SMS4_Bit64ToChar8(ElemType bit[64], ElemType ch[16]);

    unsigned char sm4Sbox(unsigned char inch);

    unsigned long sm4Lt(unsigned long ka);

    unsigned long sm4F(unsigned long x0, unsigned long x1, unsigned long x2, unsigned long x3, unsigned long rk);

    unsigned long sm4CalciRK(unsigned long ka);

    void sm4_setkey(unsigned long SK[32], unsigned char key[16]);

    void sm4_one_round(unsigned long sk[32],unsigned char input[16],unsigned char output[16]);
    void StringToHex(QString str,QByteArray &senddata);

    char ConvertHexChar(char ch);

    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);

    void FileFind(QString path);

    void FileFind_ENCRYPT(QString path, QString toPath, QString KeyPath);

    void FileFind_SendFile(QString path);

private slots:
    void on_exitButton_clicked();

    void on_OkButton_clicked();

    void setComunication();//建立链接
    void showConnected();//完成链接操作
    void beConnected();//接收到别人的链接请求
    void endSetting(quint16 tcpPort);//开启服务
    void closeConnect();//断开链接

    void on_ConnectpushButton_clicked();

private:
    Ui::FileDialog *ui;

    Sender *sender = Q_NULLPTR;
    QTcpSocket *receiver = Q_NULLPTR;
    QTimer *timer = Q_NULLPTR;
    bool Connected = false;
    bool isServerStart = false;
    bool isMulticast = false;
    QString peerAddr = "";
    QList<ServerDialog*> dialogList;
    LogDialog *logdialog=Q_NULLPTR;

    //发送数据


};

#endif // FILEDIALOG_H
