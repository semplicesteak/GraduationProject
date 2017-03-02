#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "QPixmap"
#include "QFileDialog"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();




private slots:

    void on_LoginButton_clicked();



    void on_OpenFiletoolButton_clicked();

private:
    Ui::Dialog *ui;


};




#endif // DIALOG_H
