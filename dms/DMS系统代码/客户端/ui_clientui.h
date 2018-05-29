/********************************************************************************
** Form generated from reading UI file 'clientui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTUI_H
#define UI_CLIENTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientui
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *error;
    QLabel *label_3;
    QPushButton *register_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *clientui)
    {
        if (clientui->objectName().isEmpty())
            clientui->setObjectName(QStringLiteral("clientui"));
        clientui->resize(307, 237);
        centralWidget = new QWidget(clientui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 170, 71, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 170, 71, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 51, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 110, 51, 17));
        username = new QLineEdit(centralWidget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(100, 50, 151, 31));
        password = new QLineEdit(centralWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(100, 100, 151, 31));
        error = new QLabel(centralWidget);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(70, 140, 181, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        error->setFont(font);
        error->setStyleSheet(QStringLiteral("color: rgb(255, 0, 4);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 10, 71, 31));
        label_3->setStyleSheet(QLatin1String("color: rgb(7, 40, 255);\n"
"font: 75 20pt \"TlwgMono\";"));
        register_2 = new QPushButton(centralWidget);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(120, 170, 71, 27));
        clientui->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(clientui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        clientui->setStatusBar(statusBar);

        retranslateUi(clientui);

        QMetaObject::connectSlotsByName(clientui);
    } // setupUi

    void retranslateUi(QMainWindow *clientui)
    {
        clientui->setWindowTitle(QApplication::translate("clientui", "\347\231\273\351\231\206", 0));
        pushButton->setText(QApplication::translate("clientui", "\347\231\273\351\231\206", 0));
        pushButton_2->setText(QApplication::translate("clientui", "\351\200\200\345\207\272", 0));
        label->setText(QApplication::translate("clientui", "\347\224\250\346\210\267\345\220\215", 0));
        label_2->setText(QApplication::translate("clientui", "\345\257\206    \347\240\201", 0));
        error->setText(QString());
        label_3->setText(QApplication::translate("clientui", "\347\231\273\351\231\206", 0));
        register_2->setText(QApplication::translate("clientui", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class clientui: public Ui_clientui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTUI_H
