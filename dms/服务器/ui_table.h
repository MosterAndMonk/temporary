/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *t_year;
    QRadioButton *t_mon;
    QRadioButton *t_day;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *s_year;
    QLabel *label_2;
    QComboBox *s_mon;
    QLabel *label_3;
    QComboBox *s_day;
    QLabel *label_4;
    QPushButton *t_select;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *t_close;

    void setupUi(QWidget *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName(QStringLiteral("Table"));
        Table->resize(553, 358);
        verticalLayout = new QVBoxLayout(Table);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Table);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        t_year = new QRadioButton(Table);
        t_year->setObjectName(QStringLiteral("t_year"));

        horizontalLayout->addWidget(t_year);

        t_mon = new QRadioButton(Table);
        t_mon->setObjectName(QStringLiteral("t_mon"));

        horizontalLayout->addWidget(t_mon);

        t_day = new QRadioButton(Table);
        t_day->setObjectName(QStringLiteral("t_day"));

        horizontalLayout->addWidget(t_day);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(268, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        s_year = new QComboBox(Table);
        s_year->setObjectName(QStringLiteral("s_year"));

        horizontalLayout_2->addWidget(s_year);

        label_2 = new QLabel(Table);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        s_mon = new QComboBox(Table);
        s_mon->setObjectName(QStringLiteral("s_mon"));

        horizontalLayout_2->addWidget(s_mon);

        label_3 = new QLabel(Table);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        s_day = new QComboBox(Table);
        s_day->setObjectName(QStringLiteral("s_day"));

        horizontalLayout_2->addWidget(s_day);

        label_4 = new QLabel(Table);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        t_select = new QPushButton(Table);
        t_select->setObjectName(QStringLiteral("t_select"));

        horizontalLayout_3->addWidget(t_select);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        tableView = new QTableView(Table);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(438, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        t_close = new QPushButton(Table);
        t_close->setObjectName(QStringLiteral("t_close"));

        horizontalLayout_6->addWidget(t_close);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(Table);

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QWidget *Table)
    {
        Table->setWindowTitle(QApplication::translate("Table", "\346\225\260\346\215\256\345\272\223\346\237\245\350\257\242", 0));
        label->setText(QApplication::translate("Table", "\346\237\245\350\257\242\347\261\273\345\236\213", 0));
        t_year->setText(QApplication::translate("Table", "\345\271\264\346\212\245\350\241\250", 0));
        t_mon->setText(QApplication::translate("Table", "\346\234\210\346\212\245\350\241\250", 0));
        t_day->setText(QApplication::translate("Table", "\346\227\245\346\212\245\350\241\250", 0));
        label_2->setText(QApplication::translate("Table", "\345\271\264", 0));
        label_3->setText(QApplication::translate("Table", "\346\234\210", 0));
        label_4->setText(QApplication::translate("Table", "\346\227\245", 0));
        t_select->setText(QApplication::translate("Table", "\346\237\245\350\257\242", 0));
        t_close->setText(QApplication::translate("Table", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
