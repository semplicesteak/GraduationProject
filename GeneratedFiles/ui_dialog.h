/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *Backgroundlabel;
    QFrame *line;
    QLabel *UserNamelabel;
    QLabel *IPlabel;
    QLabel *Background3label;
    QLabel *Droplabel;
    QLabel *Background2label;
    QTreeView *treeView;
    QPushButton *LoginButton;
    QLabel *label;
    QToolButton *OpenFiletoolButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(340, 631);
        Dialog->setModal(false);
        Backgroundlabel = new QLabel(Dialog);
        Backgroundlabel->setObjectName(QStringLiteral("Backgroundlabel"));
        Backgroundlabel->setGeometry(QRect(0, 0, 341, 621));
        Backgroundlabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        line = new QFrame(Dialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(7, 150, 331, 20));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        UserNamelabel = new QLabel(Dialog);
        UserNamelabel->setObjectName(QStringLiteral("UserNamelabel"));
        UserNamelabel->setGeometry(QRect(80, 30, 54, 12));
        IPlabel = new QLabel(Dialog);
        IPlabel->setObjectName(QStringLiteral("IPlabel"));
        IPlabel->setGeometry(QRect(80, 60, 61, 16));
        Background3label = new QLabel(Dialog);
        Background3label->setObjectName(QStringLiteral("Background3label"));
        Background3label->setGeometry(QRect(0, 520, 341, 101));
        Background3label->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        Droplabel = new QLabel(Dialog);
        Droplabel->setObjectName(QStringLiteral("Droplabel"));
        Droplabel->setGeometry(QRect(20, 530, 291, 71));
        Droplabel->setAcceptDrops(true);
        Droplabel->setFrameShape(QFrame::Box);
        Droplabel->setFrameShadow(QFrame::Sunken);
        Droplabel->setLineWidth(1);
        Background2label = new QLabel(Dialog);
        Background2label->setObjectName(QStringLiteral("Background2label"));
        Background2label->setEnabled(true);
        Background2label->setGeometry(QRect(0, 0, 341, 151));
        Background2label->setStyleSheet(QStringLiteral("background-color: rgb(217, 217, 217);"));
        treeView = new QTreeView(Dialog);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(30, 170, 256, 51));
        LoginButton = new QPushButton(Dialog);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setGeometry(QRect(24, 92, 61, 21));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy);
        LoginButton->setBaseSize(QSize(0, 0));
        LoginButton->setMouseTracking(true);
        LoginButton->setContextMenuPolicy(Qt::ActionsContextMenu);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 54, 12));
        OpenFiletoolButton = new QToolButton(Dialog);
        OpenFiletoolButton->setObjectName(QStringLiteral("OpenFiletoolButton"));
        OpenFiletoolButton->setGeometry(QRect(40, 540, 37, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        OpenFiletoolButton->setFont(font);
        OpenFiletoolButton->setStyleSheet(QStringLiteral("border-style:falt;"));
        Backgroundlabel->raise();
        line->raise();
        Background3label->raise();
        Droplabel->raise();
        Background2label->raise();
        UserNamelabel->raise();
        IPlabel->raise();
        treeView->raise();
        LoginButton->raise();
        label->raise();
        OpenFiletoolButton->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\345\237\272\344\272\216\345\233\275\345\257\206\347\256\227\346\263\225\347\232\204\345\212\240\345\257\206\344\272\221\347\233\230\347\263\273\347\273\237", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Dialog->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        Backgroundlabel->setText(QString());
        UserNamelabel->setText(QApplication::translate("Dialog", "TextLabel", Q_NULLPTR));
        IPlabel->setText(QApplication::translate("Dialog", "TextLabel", Q_NULLPTR));
        Background3label->setText(QString());
        Droplabel->setText(QApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\346\210\226\346\213\226\346\213\275\346\226\207\344\273\266\345\244\271\350\207\263\346\255\244\345\244\204</span></p></body></html>", Q_NULLPTR));
        Background2label->setText(QString());
        LoginButton->setText(QApplication::translate("Dialog", "LoginButton", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "TextLabel", Q_NULLPTR));
        OpenFiletoolButton->setText(QApplication::translate("Dialog", "\346\211\223\345\274\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
