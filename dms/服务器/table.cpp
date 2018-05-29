#include "table.h"
#include "ui_table.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "oracledao.h"
#include <QButtonGroup>

QString Table::sql_str;
Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    setYear();
    setMonth();
    setDay();
    dataSelect.addButton(ui->t_year,0);
    dataSelect.addButton(ui->t_mon,1);
    dataSelect.addButton(ui->t_day,2);
    db.setHostName("localhost");
    db.setDatabaseName("dms");
    db.setUserName("root");
    db.setPassword("123456");

}

Table::~Table()
{
    delete ui;
}

void Table::setYear()
{
    for(int i=2000;i<2021;i++)
        {
            ui->s_year->addItem(QString::number(i));
        }
}
void Table::setMonth()
{
    for(int i=1;i<13;i++)
    {
        ui->s_mon->addItem(QString::number(i));
    }
}
void Table::setDay()
{
    int i;
    int year = ui->s_year->currentText().toInt();
    int month= ui->s_mon->currentText().toInt();
    int day = ui->s_day->currentIndex();
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        for(i=1;i<=31;i++)
        {
            ui->s_day->addItem(QString::number(i));
            ui->s_day->setCurrentIndex(day);
        }
        break;
    case 2:
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            {
                for (i = 1; i <=29 ; i++)
                    ui->s_day->addItem(QString::number(i));
                day = (day > 29) ? 1: day;
                ui->s_day->setCurrentIndex(day);
            }
            else
            {
                for (i = 1; i <= 28; i++)
                    ui->s_day->addItem(QString::number(i));
                    day = (day > 28) ? 1: day;
                    ui->s_day->setCurrentIndex(day);
            }
            break;
    case 4:
    case 6:
    case 9:
    case 11:
        for(i=1;i<=30;i++)
        {
            ui->s_day->addItem(QString::number(i));
            day = (day > 30) ? 1: day;
            ui->s_day->setCurrentIndex(day);
        }
        break;
    }
}

void Table::on_t_select_clicked()
{
    syear=ui->s_year->currentText().toInt();
    smonth=ui->s_mon->currentText().toInt();
    sday=ui->s_day->currentText().toInt();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dms");
    db.setUserName("root");
    db.setPassword("123456");
    sql_str="select id,logname,logip,pid,from_unixtime(logintime),from_unixtime(logouttime),durations from dms.MLogRec where from_unixtime(logouttime,'%Y-%m-%d') like '";
    if(db.open()){
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    switch (dataSelect.checkedId()) {
    case 0:
        sql_str+=QString::number(syear);
        sql_str+=QString("%'");
        model->setQuery(sql_str);
        break;
    case 1:
        sql_str+=QString::number(syear);
        sql_str+=(ui->s_mon->currentText().toInt() < 10) ? "-0":"-";
        sql_str+=QString::number(smonth);
        sql_str+=QString("%'");
        model->setQuery(sql_str);
        break;
    case 2:
        sql_str+=QString::number(syear);
        sql_str+=(ui->s_mon->currentText().toInt() < 10) ? "-0":"-";
        sql_str+=QString::number(smonth);
        sql_str+=(ui->s_day->currentText().toInt() < 10) ? "-0":"-";
        sql_str+=QString::number(sday);
        sql_str+=QString("%'");
        model->setQuery(sql_str);
        break;
    default:
        break;
    }
    db.close();
    model->removeColumn(0); //不显示id属性列
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("用户名"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ip地址"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("进程号"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("登入时间"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("登出时间"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("登陆时长"));
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

}

void Table::on_t_close_clicked()
{
    close();
}
