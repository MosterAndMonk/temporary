/********************************************************************************
** Form generated from reading UI file 'swidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWIDGET_H
#define UI_SWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_swidget
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *start;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_1;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *file_select;
    QPushButton *table_select;
    QPushButton *pushButton;

    void setupUi(QMainWindow *swidget)
    {
        if (swidget->objectName().isEmpty())
            swidget->setObjectName(QStringLiteral("swidget"));
        swidget->resize(527, 284);
        centralWidget = new QWidget(swidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));

        horizontalLayout->addWidget(start);

        horizontalSpacer = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(46, 56, 255);"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit_1 = new QTextEdit(centralWidget);
        textEdit_1->setObjectName(QStringLiteral("textEdit_1"));

        verticalLayout->addWidget(textEdit_1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        file_select = new QPushButton(centralWidget);
        file_select->setObjectName(QStringLiteral("file_select"));

        horizontalLayout_3->addWidget(file_select);

        table_select = new QPushButton(centralWidget);
        table_select->setObjectName(QStringLiteral("table_select"));

        horizontalLayout_3->addWidget(table_select);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        swidget->setCentralWidget(centralWidget);

        retranslateUi(swidget);

        QMetaObject::connectSlotsByName(swidget);
    } // setupUi

    void retranslateUi(QMainWindow *swidget)
    {
        swidget->setWindowTitle(QApplication::translate("swidget", "\346\234\215\345\212\241\345\231\250", 0));
        start->setText(QApplication::translate("swidget", "\345\220\257\345\212\250", 0));
        label->setText(QApplication::translate("swidget", "\346\216\245\346\224\266\345\210\260\347\232\204\350\256\260\345\275\225", 0));
        file_select->setText(QApplication::translate("swidget", "\346\237\245\347\234\213\346\226\207\344\273\266", 0));
        table_select->setText(QApplication::translate("swidget", "\346\225\260\346\215\256\345\272\223\346\237\245\350\257\242", 0));
        pushButton->setText(QApplication::translate("swidget", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class swidget: public Ui_swidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWIDGET_H
