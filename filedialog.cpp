#include "filedialog.h"
#include "ui_filedialog.h"
#include "dialog.h"
#include "QFile"
#include "QFileInfo"
#include "QFileDialog"
#include <QComboBox>
#include <QMessageBox>
#include "QDir"

extern QString file_path;
extern QString file_name;

extern Server server;
extern QList<QString> ipList;
extern quint16 tcpPort;
extern quint16 sendPort;
extern QString IP;
extern ServerDialog *oneServer;


FileDialog::FileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileDialog)
{
    ui->setupUi(this);
    ui->NamelineEdit->setText(file_name);
    ui->RoadlineEdit->setText(file_path);

    sender=new Sender();
    timer = new QTimer(this);
    timer->setSingleShot(false);

    connect(&server, SIGNAL(newConnection()), this, SLOT(beConnected()));
    connect(this, SIGNAL(closed()), this, SLOT(closeConnect()));


}

FileDialog::~FileDialog()
{
    delete ui;
}

void FileDialog::on_exitButton_clicked()
{

    closeConnect();
    close();

}

void FileDialog::on_ConnectpushButton_clicked()
{
    setComunication();
}

//void FileDialog::on_RoadButton_clicked()
//{
    /*QString file_full, file_name, file_path;
    QFileInfo fi;

    file_full = QFileDialog::getOpenFileName(this);

    fi = QFileInfo(file_full);
    file_name = fi.fileName();
    file_path = fi.absolutePath();
    ui->RoadlineEdit->setText(file_path+file_name);
    ui->NamelineEdit->setText(file_name);*///读文件
    /*QFileInfo fi;
    QString file_path = QFileDialog::getExistingDirectory(this);
    fi=QFileInfo(file_path);
    QString file_name=fi.fileName();
    file_path.replace("/","\\");
    ui->RoadlineEdit->setText(file_path);
    ui->NamelineEdit->setText(file_name);*///读文件夹
//}

void FileDialog::on_OkButton_clicked()
{
    QString cryptCombox;
    QString crypt="加密";
    QString fillPath,toPath,keyfile;
    //setComunication();
    cryptCombox=ui->cryptcomboBox->currentText();

    if(!QString::compare(cryptCombox,crypt))
    {
        fillPath=ui->RoadlineEdit->text();
        toPath="D:/test";
        keyfile="D:/Key.txt";
        //copyDirectoryFiles(fillPath,toPath,1);
        FileFind_ENCRYPT(fillPath,toPath,keyfile);

    }
    else {
        fillPath=ui->RoadlineEdit->text();
        //fillname=ui->NamelineEdit->text();
        toPath="D:/test";
        copyDirectoryFiles(fillPath,toPath,1);
        FileFind_SendFile(fillPath);

    }

    //closeConnect();
    // close();

    //Dialog d;
    //d.show();
    //d.exec();
    this->close();


}


void FileDialog::setComunication()
{
    QString ip = IP;
    quint16 port = 5000;

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

bool FileDialog::isMulticastIp(QString ip)
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

void FileDialog::showConnected()
{
    QString statement = "";
    timer->stop();
    //ui->sendButton->setEnabled(true);
    this->Connected = true;
    statement += peerAddr;
    QMessageBox file;
    file.setText("Already conected to: "+statement);
    file.exec();
}

void FileDialog::beConnected()
{
    receiver = server.nextPendingConnection();
    {
        //ServerDialog *oneServer = new ServerDialog(this, receiver);
        //oneServer->show();
        dialogList.append(oneServer);
    }
}

void FileDialog::endSetting(quint16 tcpPort)
{
    if(!isServerStart)
    {
        server.startServer(tcpPort);
        isServerStart = true;
    }
}
void FileDialog::closeConnect()
{
    ipList.removeAll(peerAddr);
    receiver->close();
}

//遍历文件夹并发送文件信息
void FileDialog::FileFind_SendFile(QString path)
{
    //判断路径存在
    QDir dir(path);
    if(!dir.exists())
    {
        return;
    }
    //获取所选文件类型过滤器
    QStringList filters;
    filters<<QString("*.txt")<<QString("*.docx")<<QString("*.xlsx")<<QString("*.jpg");

    QDirIterator dir_iterator(path,filters,QDir::Files|QDir::NoSymLinks,QDirIterator::Subdirectories);
    QStringList string_list;
    QString WriteFileInfo;
    while (dir_iterator.hasNext()) {
        dir_iterator.next();
        QFileInfo file_info=dir_iterator.fileInfo();
        QString absolute_file_path=file_info.absoluteFilePath();
        QString file_name=file_info.fileName();
        string_list.append(absolute_file_path);
        qint64 filesize=0;
        QFile file(absolute_file_path);

        filesize=file.size();
        if(filesize<1024)
        {
            QString filesize2;
            filesize2=QString::number(filesize);
            WriteFileInfo+=file_name+"/"+filesize2+"B"+ "\n";
        }
        if(filesize>1024)
        {
            QString filesize2;
            qint64 filesize3;
            filesize3=filesize/1024;
            filesize2=QString::number(filesize3);
            WriteFileInfo+=file_name+"/"+filesize2+"KB"+ "\n";
        }


    }
    sender->sendMessage(WriteFileInfo);

}

//复制文件夹
bool FileDialog::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /* 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /* 当为目录时，递归的进行copy */
            if(!copyDirectoryFiles(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()),
                coverFileIfExist))
                return false;
        }
        else{            /* 当允许覆盖操作时，将旧文件进行删除操作 */
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }

            // 进行文件copy
            if(!QFile::copy(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()))){
                    return false;
            }
        }
    }
    return true;
}

//遍历文件夹、加密并发送
void FileDialog::FileFind_ENCRYPT(QString path,QString toPath,QString KeyPath)
{
    QString SfileName,MfileName,KfileName;
    QByteArray SfileByte,MfileByte,KfileByte;
    char* S;
    char* M;
    char* K;
    //判断路径存在
    QDir dir(path);
    if(!dir.exists())
    {
        return;
    }

    //获取所选文件类型过滤器
        QStringList filters;
        filters<<QString("*.txt")<<QString("*.docx")<<QString("*.xlsx")<<QString("*.jpg");

    QDirIterator dir_iterator(path,filters,QDir::Files|QDir::NoSymLinks,QDirIterator::Subdirectories);
    QStringList string_list;
    QString WriteFileInfo;
    while (dir_iterator.hasNext()) {
        dir_iterator.next();
        QFileInfo file_info=dir_iterator.fileInfo();
        QString absolute_file_path=file_info.absoluteFilePath();
        QString file_name=file_info.fileName();
        string_list.append(absolute_file_path);

        SfileName=absolute_file_path;
        KfileName=KeyPath;
        MfileName=toPath+"/"+file_name;
        SfileByte=SfileName.toLatin1();
        MfileByte=MfileName.toLatin1();
        KfileByte=KfileName.toLatin1();
        S=SfileByte.data();
        M=MfileByte.data();
        K=KfileByte.data();
        SMS4ENCRYPT(S,K,M);

        qint64 filesize=0;
        QFile file(absolute_file_path);
        filesize=file.size();
        if(filesize<1024)
        {
            QString filesize2;
            filesize2=QString::number(filesize);
            WriteFileInfo+=file_name+"/"+filesize2+"B"+ "\n";
        }
        if(filesize>1024)
        {
            QString filesize2;
            qint64 filesize3;
            filesize3=filesize/1024;
            filesize2=QString::number(filesize3);
            WriteFileInfo+=file_name+"/"+filesize2+"KB"+ "\n";
        }
    }
    sender->sendMessage(WriteFileInfo);
}

//遍历文件夹
void FileDialog::FileFind(QString path)
{
    //判断路径存在
    QDir dir(path);
    if(!dir.exists())
    {
        return;
    }

    QDirIterator dir_iterator(path,QDirIterator::Subdirectories);
    QStringList string_list;
    while (dir_iterator.hasNext()) {
        dir_iterator.next();
        QFileInfo file_info=dir_iterator.fileInfo();
        QString absolute_file_path=file_info.absoluteFilePath();
        string_list.append(absolute_file_path);

    }
}





//随机数16进制转换
void FileDialog::StringToHex(QString str,QByteArray &senddata)
{
    int hexdata/*,lowhexdata*/;
    int hexdatalen=0;
    int len=str.length();
    senddata.resize(len/2);
    char /*lstr,*/hstr;

    for(int i=0;i<len;)
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len+1)
            break;
        //lstr=str[i].toLatin1();
        hexdata=ConvertHexChar(hstr);
        //lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16)/* || (lowhexdata == 16)*/)
            break;
        /*else
            hexdata = hexdata*16+lowhexdata;
        i++;*/
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;


    }
    senddata.resize(hexdatalen);
}

char FileDialog::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return ch-ch;//不在0-f范围内的会发送成0
}

//SM4
#ifndef GET_ULONG_BE
#define GET_ULONG_BE(n,b,i)                             \
{                                                       \
    (n) = ( (unsigned long) (b)[(i)    ] << 24 )        \
    | ( (unsigned long) (b)[(i) + 1] << 16 )        \
    | ( (unsigned long) (b)[(i) + 2] <<  8 )        \
    | ( (unsigned long) (b)[(i) + 3]       );       \
    }
#endif

#ifndef PUT_ULONG_BE
#define PUT_ULONG_BE(n,b,i)                             \
{                                                       \
    (b)[(i)    ] = (unsigned char) ( (n) >> 24 );       \
    (b)[(i) + 1] = (unsigned char) ( (n) >> 16 );       \
    (b)[(i) + 2] = (unsigned char) ( (n) >>  8 );       \
    (b)[(i) + 3] = (unsigned char) ( (n)       );       \
    }
#endif


#define  SHL(x,n) (((x) & 0xFFFFFFFF) << n)
#define ROTL(x,n) (SHL((x),n) | ((x) >> (32 - n)))

#define SWAP(a,b) { unsigned long t = a; a = b; b = t; t = 0; }

static const unsigned char SboxTable[16][16] =
{
    { 0xd6, 0x90, 0xe9, 0xfe, 0xcc, 0xe1, 0x3d, 0xb7, 0x16, 0xb6, 0x14, 0xc2, 0x28, 0xfb, 0x2c, 0x05 },
    { 0x2b, 0x67, 0x9a, 0x76, 0x2a, 0xbe, 0x04, 0xc3, 0xaa, 0x44, 0x13, 0x26, 0x49, 0x86, 0x06, 0x99 },
    { 0x9c, 0x42, 0x50, 0xf4, 0x91, 0xef, 0x98, 0x7a, 0x33, 0x54, 0x0b, 0x43, 0xed, 0xcf, 0xac, 0x62 },
    { 0xe4, 0xb3, 0x1c, 0xa9, 0xc9, 0x08, 0xe8, 0x95, 0x80, 0xdf, 0x94, 0xfa, 0x75, 0x8f, 0x3f, 0xa6 },
    { 0x47, 0x07, 0xa7, 0xfc, 0xf3, 0x73, 0x17, 0xba, 0x83, 0x59, 0x3c, 0x19, 0xe6, 0x85, 0x4f, 0xa8 },
    { 0x68, 0x6b, 0x81, 0xb2, 0x71, 0x64, 0xda, 0x8b, 0xf8, 0xeb, 0x0f, 0x4b, 0x70, 0x56, 0x9d, 0x35 },
    { 0x1e, 0x24, 0x0e, 0x5e, 0x63, 0x58, 0xd1, 0xa2, 0x25, 0x22, 0x7c, 0x3b, 0x01, 0x21, 0x78, 0x87 },
    { 0xd4, 0x00, 0x46, 0x57, 0x9f, 0xd3, 0x27, 0x52, 0x4c, 0x36, 0x02, 0xe7, 0xa0, 0xc4, 0xc8, 0x9e },
    { 0xea, 0xbf, 0x8a, 0xd2, 0x40, 0xc7, 0x38, 0xb5, 0xa3, 0xf7, 0xf2, 0xce, 0xf9, 0x61, 0x15, 0xa1 },
    { 0xe0, 0xae, 0x5d, 0xa4, 0x9b, 0x34, 0x1a, 0x55, 0xad, 0x93, 0x32, 0x30, 0xf5, 0x8c, 0xb1, 0xe3 },
    { 0x1d, 0xf6, 0xe2, 0x2e, 0x82, 0x66, 0xca, 0x60, 0xc0, 0x29, 0x23, 0xab, 0x0d, 0x53, 0x4e, 0x6f },
    { 0xd5, 0xdb, 0x37, 0x45, 0xde, 0xfd, 0x8e, 0x2f, 0x03, 0xff, 0x6a, 0x72, 0x6d, 0x6c, 0x5b, 0x51 },
    { 0x8d, 0x1b, 0xaf, 0x92, 0xbb, 0xdd, 0xbc, 0x7f, 0x11, 0xd9, 0x5c, 0x41, 0x1f, 0x10, 0x5a, 0xd8 },
    { 0x0a, 0xc1, 0x31, 0x88, 0xa5, 0xcd, 0x7b, 0xbd, 0x2d, 0x74, 0xd0, 0x12, 0xb8, 0xe5, 0xb4, 0xb0 },
    { 0x89, 0x69, 0x97, 0x4a, 0x0c, 0x96, 0x77, 0x7e, 0x65, 0xb9, 0xf1, 0x09, 0xc5, 0x6e, 0xc6, 0x84 },
    { 0x18, 0xf0, 0x7d, 0xec, 0x3a, 0xdc, 0x4d, 0x20, 0x79, 0xee, 0x5f, 0x3e, 0xd7, 0xcb, 0x39, 0x48 }
};

static const unsigned long FK[4] = { 0xa3b1bac6, 0x56aa3350, 0x677d9197, 0xb27022dc };

static const unsigned long CK[32] =
{
    0x00070e15, 0x1c232a31, 0x383f464d, 0x545b6269,
    0x70777e85, 0x8c939aa1, 0xa8afb6bd, 0xc4cbd2d9,
    0xe0e7eef5, 0xfc030a11, 0x181f262d, 0x343b4249,
    0x50575e65, 0x6c737a81, 0x888f969d, 0xa4abb2b9,
    0xc0c7ced5, 0xdce3eaf1, 0xf8ff060d, 0x141b2229,
    0x30373e45, 0x4c535a61, 0x686f767d, 0x848b9299,
    0xa0a7aeb5, 0xbcc3cad1, 0xd8dfe6ed, 0xf4fb0209,
    0x10171e25, 0x2c333a41, 0x484f565d, 0x646b7279
};


//S盒置换
unsigned char FileDialog::sm4Sbox(unsigned char inch)
{
    unsigned char *pTable = (unsigned char *)SboxTable;
    unsigned char retVal = (unsigned char)(pTable[inch]);
    return retVal;
}
//合成置换T
unsigned long FileDialog::sm4Lt(unsigned long ka)
{
    unsigned long bb = 0;
    unsigned long c = 0;
    unsigned char a[4];
    unsigned char b[4];
    PUT_ULONG_BE(ka, a, 0);
    b[0] = sm4Sbox(a[0]);
    b[1] = sm4Sbox(a[1]);
    b[2] = sm4Sbox(a[2]);
    b[3] = sm4Sbox(a[3]);
    GET_ULONG_BE(bb, b, 0)
            c = bb ^ (ROTL(bb, 2)) ^ (ROTL(bb, 10)) ^ (ROTL(bb, 18)) ^ (ROTL(bb, 24));
    return c;
}

//轮函数F
unsigned long FileDialog::sm4F(unsigned long x0, unsigned long x1, unsigned long x2, unsigned long x3, unsigned long rk)
{
    return (x0^sm4Lt(x1^x2^x3^rk));
}

//合成置换T'
unsigned long FileDialog::sm4CalciRK(unsigned long ka)
{
    unsigned long bb = 0;
    unsigned long rk = 0;
    unsigned char a[4];
    unsigned char b[4];
    PUT_ULONG_BE(ka, a, 0);
    b[0] = sm4Sbox(a[0]);
    b[1] = sm4Sbox(a[1]);
    b[2] = sm4Sbox(a[2]);
    b[3] = sm4Sbox(a[3]);
    GET_ULONG_BE(bb, b, 0)
            rk = bb ^ (ROTL(bb, 13)) ^ (ROTL(bb, 23));
    return rk;
}

//密钥扩展
void FileDialog::sm4_setkey(unsigned long SK[32], unsigned char key[16])
{
    unsigned long MK[4];
    unsigned long k[36];
    unsigned long i = 0;

    GET_ULONG_BE(MK[0], key, 0);
    GET_ULONG_BE(MK[1], key, 4);
    GET_ULONG_BE(MK[2], key, 8);
    GET_ULONG_BE(MK[3], key, 12);
    k[0] = MK[0] ^ FK[0];
    k[1] = MK[1] ^ FK[1];
    k[2] = MK[2] ^ FK[2];
    k[3] = MK[3] ^ FK[3];
    for (; i<32; i++)
    {
        k[i + 4] = k[i] ^ (sm4CalciRK(k[i + 1] ^ k[i + 2] ^ k[i + 3] ^ CK[i]));
        SK[i] = k[i + 4];
    }
}

//加密128比特数据
void FileDialog::sm4_one_round(unsigned long sk[32],
unsigned char input[16],
unsigned char output[16])
{
    unsigned long i = 0;
    unsigned long ulbuf[36];

    memset(ulbuf, 0, sizeof(ulbuf));
    GET_ULONG_BE(ulbuf[0], input, 0);
    GET_ULONG_BE(ulbuf[1], input, 4);
    GET_ULONG_BE(ulbuf[2], input, 8);
    GET_ULONG_BE(ulbuf[3], input, 12);
    while (i<32)
    {
        ulbuf[i + 4] = sm4F(ulbuf[i], ulbuf[i + 1], ulbuf[i + 2], ulbuf[i + 3], sk[i]);
        i++;
    }
    PUT_ULONG_BE(ulbuf[35], output, 0);
    PUT_ULONG_BE(ulbuf[34], output, 4);
    PUT_ULONG_BE(ulbuf[33], output, 8);
    PUT_ULONG_BE(ulbuf[32], output, 12);
}

//将轮密钥设为加密密钥
void FileDialog::sm4_setkey_enc(sm4_context *ctx, unsigned char key[16])
{
    ctx->mode = SM4_ENCRYPT;
    sm4_setkey(ctx->sk, key);
}

//将轮密钥设为解密密钥
void FileDialog::sm4_setkey_dec(sm4_context *ctx, unsigned char key[16])
{
    int i;
    ctx->mode = SM4_ENCRYPT;
    sm4_setkey(ctx->sk, key);
    for (i = 0; i < 16; i++)
    {
        SWAP(ctx->sk[i], ctx->sk[31 - i]);
    }
}

void FileDialog::SMS4ENCRYPT(char *plainFile, char* str, char *cipherFile)
{
    FILE *plain, *cipher,*key;
    sm4_context block;
    int count;
    unsigned char plainBlock[16], cipherBlock[16], keyBlock[16], cbc1[16] = { 0,1,2,3,4,5,6,7,8,9,'a','b','c','d','e','f' }, cbc2[16];

    if ((plain = fopen(plainFile, "rb")) == NULL)
    {
        QMessageBox file;
        file.setText("plainFile can't open!");
        file.exec();
    }
    if ((key = fopen(str, "rb")) == NULL)
    {
        QMessageBox file;
        file.setText("keyFile can't open!");
        file.exec();
    }
    if ((cipher = fopen(cipherFile, "wb")) == NULL)
    {
        QMessageBox file;
        file.setText("encryptFile can't open!");
        file.exec();
    }

    fread(keyBlock, sizeof(char), 16, key);

    //密钥扩展
    sm4_setkey_enc(&block, (unsigned char*)keyBlock);
    while (!feof(plain))
    {
        count = fread(plainBlock, sizeof(char), 16, plain);

        if (count == 16)
        {
            for (int i = 0; i < 16; i++)
            {
                cbc2[i] = cbc1[i] ^ plainBlock[i];
            }

            sm4_one_round(block.sk, cbc2, cipherBlock);
            fwrite(cipherBlock, sizeof(char), 16, cipher);

        }
        for (int j = 0; j < 16; j++)
        {
            cbc1[j] = cipherBlock[j];
        }
    }
    if (count<16){
        //填充
        memset(plainBlock + count, '\0', 15 - count);
        //最后一个字符保存包括最后一个字符在内的所填充的字符数量
        plainBlock[15] = 16 - count;
        for (int i = 0; i < 16; i++)
        {
            cbc2[i] = cbc1[i]^plainBlock[i];
        }
        sm4_one_round(block.sk, cbc2, cipherBlock);
        fwrite(cipherBlock, sizeof(char), 16, cipher);
    }

    fclose(plain);
    fclose(cipher);
    fclose(key);


    QMessageBox fileBox;
    fileBox.setText("succefful!");
    fileBox.exec();

}

//解密函数
void FileDialog::SMS4DECRYPT(char* plainFile, char* str, char* cipherFile)
{
    FILE *plain, *cipher,*key;
    sm4_context block;
    int count;
    unsigned char plainBlock[16], cipherBlock[16], keyBlock[16], cbc1[16] = { 0,1,2,3,4,5,6,7,8,9,'a','b','c','d','e','f' }, cbc2[16];
    if ((cipher = fopen(cipherFile, "rb")) == NULL)
    {
        QMessageBox file;
        file.setText("encryptFile can't open!");
        file.exec();
    }
    if ((key = fopen(str, "rb")) == NULL)
    {
        QMessageBox file;
        file.setText("plainFile can't open!");
        file.exec();
    }
    if ((plain = fopen(plainFile, "wb")) == NULL)
    {
        QMessageBox file;
        file.setText("plainFile can't open!");
        file.exec();
    }
    fread(keyBlock, sizeof(char), 16, key);

    //密钥扩展
    sm4_setkey_dec(&block, (unsigned char*)keyBlock);
    //取文件长度
    long times = 0;//计数器
    fseek(cipher, 0, SEEK_END);	//将文件指针置尾
    long fileLen = ftell(cipher);	//取文件指针当前位置
    rewind(cipher);				//将文件指针重指向文件头
    while (1)
    {
        //密文的字节数一定是16的整数倍
        fread(cipherBlock, sizeof(char), 16, cipher);
        sm4_one_round(block.sk, cipherBlock, plainBlock);
        for (int i = 0; i < 16; i++)
        {
            cbc2[i] = cbc1[i] ^ plainBlock[i];
        }

        //for (int j = 0; j < 16; j++)
        //{
        //	cbc1[j] = cipherBlock[j];
        //}
        times += 16;
        if (times < fileLen)
        {
            fwrite(cbc2, sizeof(char), 16, plain);
        }
        else
        {
            break;
        }
        for (int j = 0; j < 16; j++)
        {
            cbc1[j] = cipherBlock[j];
        }
    }
    //判断末尾是否被填充
    if (cbc2[15] < 16) {
        for (count = 16 - cbc2[15]; count < 15; count++) {
            if (cbc2[count] != '\0') {
                break;
            }
        }
    }
    if (count == 15) {//有填充
        fwrite(cbc2, sizeof(char), 16 - cbc2[15], plain);
    }
    else {//无填充
        fwrite(cbc2, sizeof(char), 16, plain);
    }

    fclose(plain);
    fclose(cipher);
    fclose(key);
    QMessageBox fileBox;
    fileBox.setText("successful");
    fileBox.exec();
}





