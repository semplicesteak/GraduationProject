/********************************************************************************
** Form generated from reading UI file 'serverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERDIALOG_H
#define UI_SERVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerDialog
{
public:
    QTextEdit *conversation;
    QTextEdit *view;
    QPushButton *sendButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *ipLabel;
    QLineEdit *ipLine;
    QPushButton *pushButton;

    void setupUi(QDialog *ServerDialog)
    {
        if (ServerDialog->objectName().isEmpty())
            ServerDialog->setObjectName(QStringLiteral("ServerDialog"));
        ServerDialog->resize(517, 422);
        conversation = new QTextEdit(ServerDialog);
        conversation->setObjectName(QStringLiteral("conversation"));
        conversation->setGeometry(QRect(30, 80, 421, 181));
        view = new QTextEdit(ServerDialog);
        view->setObjectName(QStringLiteral("view"));
        view->setGeometry(QRect(30, 290, 421, 51));
        sendButton = new QPushButton(ServerDialog);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(380, 350, 75, 23));
        layoutWidget = new QWidget(ServerDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(31, 35, 231, 31));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ipLabel = new QLabel(layoutWidget);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));

        gridLayout->addWidget(ipLabel, 0, 0, 1, 1);

        ipLine = new QLineEdit(layoutWidget);
        ipLine->setObjectName(QStringLiteral("ipLine"));

        gridLayout->addWidget(ipLine, 0, 1, 1, 1);

        pushButton = new QPushButton(ServerDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 350, 75, 23));

        retranslateUi(ServerDialog);

        QMetaObject::connectSlotsByName(ServerDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerDialog)
    {
        ServerDialog->setWindowTitle(QApplication::translate("ServerDialog", "ServerDialog", Q_NULLPTR));
        sendButton->setText(QApplication::translate("ServerDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        ipLabel->setText(QApplication::translate("ServerDialog", "\346\266\210\346\201\257\346\235\245\350\207\252\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ServerDialog", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServerDialog: public Ui_ServerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERDIALOG_H
