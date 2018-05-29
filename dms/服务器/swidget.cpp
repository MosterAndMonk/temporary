#include "swidget.h"
#include "ui_swidget.h"
#include "data.h"
#include "oracledao.h"
#include <QSqlDatabase>
#include "server.h"
#include "filedao.h"
#include <QDebug>
#include <QTimer>
#include "logqueue.h"
#include <QFile>
#include <QDesktopServices>

swidget::swidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::swidget)
{
    ui->setupUi(this);
    connect(ui->start,SIGNAL(clicked()),this,SLOT(on_start_clicked()));
    connect(ui->table_select,SIGNAL(clicked()),this,SLOT(on_table_select_clicked()));
    qtm = new QTimer();
    qtm->start(1000);
    connect(qtm, SIGNAL(timeout()), this, SLOT(on_time()));
    connect(this, SIGNAL(beLogs(MLogRec)), this, SLOT(on_send(MLogRec)));
    connect(ui->file_select,SIGNAL(clicked()),this,SLOT(on_file_select_clicked()));
}

void swidget::on_time()
{
    list<MLogRec> ll = logque.myLog;
    while(!ll.empty())
    {
        emit(beLogs(ll.front()));
        ll.pop_front();
    }
}


swidget::~swidget()
{
    delete ui;
}

void swidget::on_send(MLogRec log)
{
    QString str(log.logname);
    str +="     ";
    str += QString(log.logip);
    str +="     ";
    str += QString::number(log.pid);
    str +="     ";
    str += QString::number(log.logintime );
    str +="     ";
    str += QString::number(log.logouttime );
    str +="     ";
    str += QString::number(log.durations );
    ui->textEdit_1->append(str);
}

void swidget::on_start_clicked()
{
    my_thread.start();

}

void swidget::on_table_select_clicked()
{
    two.show();
    this->hide();
}

void swidget::on_file_select_clicked()
{
    QString runPath = QCoreApplication::applicationDirPath();       //获取exe路劲。

        QString helpName = "filedao.txt";

        QString helpPath = QString("%1/%2").arg(runPath).arg(helpName);

        QFile bfilePath(helpPath);

        if(!bfilePath.exists()){

            return;

        }

        QString filePath = "" + helpPath;   //打开文件夹用filse:///,打开网页用http://

        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));

}


void swidget::on_pushButton_clicked()
{
    close();
}
