/********************************************************************************
** Form generated from reading UI file 'logdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGDIALOG_H
#define UI_LOGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogDialog
{
public:
    QLabel *Backgroundlabel;
    QPushButton *LoginButton;
    QPushButton *exitButton;
    QLabel *serverlabel;
    QLabel *userlabel;
    QLabel *passwordlabel;
    QLineEdit *UserNamelineEdit;
    QLineEdit *PasswordlineEdit;
    QLabel *Devicelabel;
    QLineEdit *devicelineEdit;
    QLineEdit *PortEdit;
    QLineEdit *iplineEdit;
    QPushButton *ConnectpushButton;

    void setupUi(QDialog *LogDialog)
    {
        if (LogDialog->objectName().isEmpty())
            LogDialog->setObjectName(QStringLiteral("LogDialog"));
        LogDialog->resize(400, 300);
        Backgroundlabel = new QLabel(LogDialog);
        Backgroundlabel->setObjectName(QStringLiteral("Backgroundlabel"));
        Backgroundlabel->setGeometry(QRect(3, 1, 391, 291));
        Backgroundlabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        LoginButton = new QPushButton(LogDialog);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setEnabled(false);
        LoginButton->setGeometry(QRect(210, 250, 75, 23));
        LoginButton->setFocusPolicy(Qt::NoFocus);
        exitButton = new QPushButton(LogDialog);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(300, 250, 75, 23));
        exitButton->setFocusPolicy(Qt::NoFocus);
        serverlabel = new QLabel(LogDialog);
        serverlabel->setObjectName(QStringLiteral("serverlabel"));
        serverlabel->setGeometry(QRect(53, 50, 61, 20));
        userlabel = new QLabel(LogDialog);
        userlabel->setObjectName(QStringLiteral("userlabel"));
        userlabel->setGeometry(QRect(60, 100, 41, 16));
        passwordlabel = new QLabel(LogDialog);
        passwordlabel->setObjectName(QStringLiteral("passwordlabel"));
        passwordlabel->setGeometry(QRect(60, 150, 31, 16));
        UserNamelineEdit = new QLineEdit(LogDialog);
        UserNamelineEdit->setObjectName(QStringLiteral("UserNamelineEdit"));
        UserNamelineEdit->setGeometry(QRect(130, 100, 231, 20));
        PasswordlineEdit = new QLineEdit(LogDialog);
        PasswordlineEdit->setObjectName(QStringLiteral("PasswordlineEdit"));
        PasswordlineEdit->setGeometry(QRect(130, 150, 231, 20));
        Devicelabel = new QLabel(LogDialog);
        Devicelabel->setObjectName(QStringLiteral("Devicelabel"));
        Devicelabel->setGeometry(QRect(40, 200, 81, 16));
        devicelineEdit = new QLineEdit(LogDialog);
        devicelineEdit->setObjectName(QStringLiteral("devicelineEdit"));
        devicelineEdit->setGeometry(QRect(130, 200, 231, 20));
        devicelineEdit->setMouseTracking(false);
        devicelineEdit->setDragEnabled(true);
        devicelineEdit->setReadOnly(true);
        PortEdit = new QLineEdit(LogDialog);
        PortEdit->setObjectName(QStringLiteral("PortEdit"));
        PortEdit->setGeometry(QRect(310, 50, 51, 20));
        iplineEdit = new QLineEdit(LogDialog);
        iplineEdit->setObjectName(QStringLiteral("iplineEdit"));
        iplineEdit->setGeometry(QRect(130, 50, 171, 20));
        ConnectpushButton = new QPushButton(LogDialog);
        ConnectpushButton->setObjectName(QStringLiteral("ConnectpushButton"));
        ConnectpushButton->setGeometry(QRect(120, 250, 75, 23));
        ConnectpushButton->setFocusPolicy(Qt::StrongFocus);

        retranslateUi(LogDialog);

        QMetaObject::connectSlotsByName(LogDialog);
    } // setupUi

    void retranslateUi(QDialog *LogDialog)
    {
        LogDialog->setWindowTitle(QApplication::translate("LogDialog", "\345\237\272\344\272\216\345\233\275\345\257\206\347\256\227\346\263\225\347\232\204\345\212\240\345\257\206\344\272\221\347\233\230\347\263\273\347\273\237", Q_NULLPTR));
        Backgroundlabel->setText(QString());
        LoginButton->setText(QApplication::translate("LogDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        exitButton->setText(QApplication::translate("LogDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        serverlabel->setText(QApplication::translate("LogDialog", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        userlabel->setText(QApplication::translate("LogDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        passwordlabel->setText(QApplication::translate("LogDialog", "\345\257\206 \347\240\201", Q_NULLPTR));
        Devicelabel->setText(QApplication::translate("LogDialog", "\347\231\273\345\275\225\350\256\276\345\244\207\345\220\215\347\247\260", Q_NULLPTR));
        PortEdit->setText(QApplication::translate("LogDialog", "5000", Q_NULLPTR));
        iplineEdit->setText(QApplication::translate("LogDialog", "127.0.0.1", Q_NULLPTR));
        ConnectpushButton->setText(QApplication::translate("LogDialog", "\350\277\236\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogDialog: public Ui_LogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGDIALOG_H
