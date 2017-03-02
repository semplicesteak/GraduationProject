#include "dialog.h"
#include "ui_dialog.h"
#include "QTreeView"
#include "logdialog.h"
#include "QLabel"
#include "filedialog.h"
#include "QFile"
#include "QFileInfo"
#include "QFileDialog"
#include <QComboBox>
#include <QMessageBox>
#include "QDir"
//#include "treeview.h"
extern QString Username;
extern QString IP;

QString file_name;
QString file_path;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->UserNamelabel->setText(Username);
    ui->IPlabel->setText(IP);


}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_LoginButton_clicked()
{

}


void Dialog::on_OpenFiletoolButton_clicked()
{
    QFileInfo fi;
    file_path = QFileDialog::getExistingDirectory(this);
    fi=QFileInfo(file_path);
    file_name=fi.fileName();
    file_path.replace("/","\\");
    //ui->RoadlineEdit->setText(file_path);
    //ui->NamelineEdit->setText(file_name);
    FileDialog p;
    p.show();
    p.exec();
}
