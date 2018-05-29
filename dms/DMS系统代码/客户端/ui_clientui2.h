/********************************************************************************
** Form generated from reading UI file 'clientui2.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTUI2_H
#define UI_CLIENTUI2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientui2
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *clientui2)
    {
        if (clientui2->objectName().isEmpty())
            clientui2->setObjectName(QStringLiteral("clientui2"));
        clientui2->resize(543, 499);
        centralwidget = new QWidget(clientui2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 71, 17));
        label_2->setStyleSheet(QStringLiteral("color: rgb(69, 255, 28);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 300, 91, 17));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 0, 4);"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(310, 50, 211, 51));
        lcdNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 110, 501, 181));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 320, 501, 131));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(21, 11, 496, 33));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(12, 118, 199);\n"
"font: 15pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(348, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(40, 460, 484, 30));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        clientui2->setCentralWidget(centralwidget);

        retranslateUi(clientui2);

        QMetaObject::connectSlotsByName(clientui2);
    } // setupUi

    void retranslateUi(QMainWindow *clientui2)
    {
        clientui2->setWindowTitle(QApplication::translate("clientui2", "\345\256\242\346\210\267\346\234\272", 0));
        label_2->setText(QApplication::translate("clientui2", "\345\214\271\351\205\215\346\210\220\345\212\237\357\274\232", 0));
        label_3->setText(QApplication::translate("clientui2", "\346\234\252\345\214\271\351\205\215\346\225\260\346\215\256\357\274\232", 0));
        label->setText(QApplication::translate("clientui2", "\346\225\260\346\215\256\351\207\207\351\233\206\345\256\242\346\210\267\346\234\272", 0));
        pushButton->setText(QApplication::translate("clientui2", "\345\220\257\345\212\250", 0));
        pushButton_2->setText(QApplication::translate("clientui2", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class clientui2: public Ui_clientui2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTUI2_H
