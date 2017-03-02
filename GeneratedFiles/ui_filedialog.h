/********************************************************************************
** Form generated from reading UI file 'filedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEDIALOG_H
#define UI_FILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileDialog
{
public:
    QLabel *Backgroundlabel;
    QLabel *Roadlabel;
    QLabel *Namelabel;
    QLineEdit *RoadlineEdit;
    QLineEdit *NamelineEdit;
    QComboBox *cryptcomboBox;
    QPushButton *OkButton;
    QPushButton *exitButton;
    QLabel *Keylabel;
    QLabel *ReKeylabel;
    QLineEdit *KeylineEdit;
    QLineEdit *ReKeylineEdit;
    QProgressBar *clientprogressBar;
    QLabel *clientStatusLabel;
    QPushButton *ConnectpushButton;

    void setupUi(QDialog *FileDialog)
    {
        if (FileDialog->objectName().isEmpty())
            FileDialog->setObjectName(QStringLiteral("FileDialog"));
        FileDialog->resize(392, 300);
        Backgroundlabel = new QLabel(FileDialog);
        Backgroundlabel->setObjectName(QStringLiteral("Backgroundlabel"));
        Backgroundlabel->setGeometry(QRect(0, 0, 391, 291));
        Backgroundlabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Roadlabel = new QLabel(FileDialog);
        Roadlabel->setObjectName(QStringLiteral("Roadlabel"));
        Roadlabel->setGeometry(QRect(30, 40, 31, 16));
        Namelabel = new QLabel(FileDialog);
        Namelabel->setObjectName(QStringLiteral("Namelabel"));
        Namelabel->setGeometry(QRect(20, 90, 54, 12));
        RoadlineEdit = new QLineEdit(FileDialog);
        RoadlineEdit->setObjectName(QStringLiteral("RoadlineEdit"));
        RoadlineEdit->setGeometry(QRect(90, 40, 281, 20));
        NamelineEdit = new QLineEdit(FileDialog);
        NamelineEdit->setObjectName(QStringLiteral("NamelineEdit"));
        NamelineEdit->setGeometry(QRect(90, 90, 131, 20));
        cryptcomboBox = new QComboBox(FileDialog);
        cryptcomboBox->setObjectName(QStringLiteral("cryptcomboBox"));
        cryptcomboBox->setGeometry(QRect(300, 90, 69, 22));
        OkButton = new QPushButton(FileDialog);
        OkButton->setObjectName(QStringLiteral("OkButton"));
        OkButton->setGeometry(QRect(230, 260, 75, 23));
        exitButton = new QPushButton(FileDialog);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(310, 260, 75, 23));
        Keylabel = new QLabel(FileDialog);
        Keylabel->setObjectName(QStringLiteral("Keylabel"));
        Keylabel->setGeometry(QRect(30, 190, 31, 16));
        ReKeylabel = new QLabel(FileDialog);
        ReKeylabel->setObjectName(QStringLiteral("ReKeylabel"));
        ReKeylabel->setGeometry(QRect(20, 230, 51, 16));
        KeylineEdit = new QLineEdit(FileDialog);
        KeylineEdit->setObjectName(QStringLiteral("KeylineEdit"));
        KeylineEdit->setGeometry(QRect(90, 190, 291, 20));
        ReKeylineEdit = new QLineEdit(FileDialog);
        ReKeylineEdit->setObjectName(QStringLiteral("ReKeylineEdit"));
        ReKeylineEdit->setGeometry(QRect(90, 230, 291, 20));
        clientprogressBar = new QProgressBar(FileDialog);
        clientprogressBar->setObjectName(QStringLiteral("clientprogressBar"));
        clientprogressBar->setGeometry(QRect(30, 140, 341, 23));
        clientprogressBar->setValue(24);
        clientStatusLabel = new QLabel(FileDialog);
        clientStatusLabel->setObjectName(QStringLiteral("clientStatusLabel"));
        clientStatusLabel->setGeometry(QRect(230, 90, 61, 16));
        ConnectpushButton = new QPushButton(FileDialog);
        ConnectpushButton->setObjectName(QStringLiteral("ConnectpushButton"));
        ConnectpushButton->setGeometry(QRect(150, 260, 75, 23));

        retranslateUi(FileDialog);

        QMetaObject::connectSlotsByName(FileDialog);
    } // setupUi

    void retranslateUi(QDialog *FileDialog)
    {
        FileDialog->setWindowTitle(QApplication::translate("FileDialog", "Dialog", Q_NULLPTR));
        Backgroundlabel->setText(QString());
        Roadlabel->setText(QApplication::translate("FileDialog", "\350\267\257\345\276\204", Q_NULLPTR));
        Namelabel->setText(QApplication::translate("FileDialog", "\346\226\207\344\273\266\345\244\271\345\220\215", Q_NULLPTR));
        cryptcomboBox->clear();
        cryptcomboBox->insertItems(0, QStringList()
         << QApplication::translate("FileDialog", "\346\227\240\345\257\206", Q_NULLPTR)
         << QApplication::translate("FileDialog", "\345\212\240\345\257\206", Q_NULLPTR)
        );
        OkButton->setText(QApplication::translate("FileDialog", "\344\270\212\344\274\240", Q_NULLPTR));
        exitButton->setText(QApplication::translate("FileDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        Keylabel->setText(QApplication::translate("FileDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        ReKeylabel->setText(QApplication::translate("FileDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        clientStatusLabel->setText(QApplication::translate("FileDialog", "<html><head/><body><p align=\"center\">\346\230\257\345\220\246\345\212\240\345\257\206</p></body></html>", Q_NULLPTR));
        ConnectpushButton->setText(QApplication::translate("FileDialog", "\350\277\236\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileDialog: public Ui_FileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEDIALOG_H
