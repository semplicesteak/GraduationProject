//#include "dialog.h"
#include <QApplication>
#include <logdialog.h>
//#include <filedialog.h>

Server server;
QList<QString> ipList;
quint16 tcpPort = 5000;
//quint16 udpPort = 3000;
quint16 sendPort = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogDialog w;
    w.show();
    return a.exec();
}
