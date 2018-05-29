/********************************************************************************
** Form generated from reading UI file 'zhuce.ui'
**
** Created: Fri Jul 1 11:30:31 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUCE_H
#define UI_ZHUCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zhuce
{
public:
    QWidget *centralwidget;
    QLineEdit *uname;
    QLineEdit *passwd_1;
    QLineEdit *passwd_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *zhuce)
    {
        if (zhuce->objectName().isEmpty())
            zhuce->setObjectName(QString::fromUtf8("zhuce"));
        zhuce->resize(280, 217);
        centralwidget = new QWidget(zhuce);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        uname = new QLineEdit(centralwidget);
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(110, 20, 113, 27));
        passwd_1 = new QLineEdit(centralwidget);
        passwd_1->setObjectName(QString::fromUtf8("passwd_1"));
        passwd_1->setGeometry(QRect(110, 60, 113, 27));
        passwd_2 = new QLineEdit(centralwidget);
        passwd_2->setObjectName(QString::fromUtf8("passwd_2"));
        passwd_2->setGeometry(QRect(110, 100, 113, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(55, 25, 66, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(55, 65, 66, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 105, 66, 17));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 160, 71, 27));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 160, 81, 27));
        zhuce->setCentralWidget(centralwidget);
        menubar = new QMenuBar(zhuce);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 280, 26));
        zhuce->setMenuBar(menubar);
        statusbar = new QStatusBar(zhuce);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        zhuce->setStatusBar(statusbar);

        retranslateUi(zhuce);

        QMetaObject::connectSlotsByName(zhuce);
    } // setupUi

    void retranslateUi(QMainWindow *zhuce)
    {
        zhuce->setWindowTitle(QApplication::translate("zhuce", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("zhuce", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("zhuce", "\345\257\206    \347\240\201", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("zhuce", "\347\241\256\350\256\244\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("zhuce", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("zhuce", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class zhuce: public Ui_zhuce {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCE_H
