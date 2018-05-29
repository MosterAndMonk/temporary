#include "clientui2.h"
#include "ui_clientui2.h"
#include "mydialog.h"#include <QLCDNumber>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include "LogReader.h"
#include "LogSender.h"
#include "Client.h"
#include <iostream>
#include <cstring>
#include "ConsoleSender.h"
#include "SocketSender.h"

clientui2::clientui2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientui2)

{
    ui->setupUi(this);
    QTimer *timer=new QTimer;
    ui->lcdNumber->setDigitCount(20);
    ui->lcdNumber->setPalette(Qt::black);
    ui->lcdNumber->setLineWidth(0);
    ui->lcdNumber->display("yyyy-MM-dd hh:mm:ss");
    connect(timer,SIGNAL(timeout()),this,SLOT(chTime()));
    timer->start(1000);
}

clientui2::~clientui2()
{
    delete ui;
}

void clientui2::on_pushButton_clicked()
{
    try
    {
        LogReader reader("./wtmpx","./logins.dat");
     //  ConsoleSender sender;
           SocketSender sender("./fail.dat", 2004, "127.0.0.1");
        //Client *client = new Client(reader,sender);
        Client client(reader, sender);
        client.dataMine();
        list<MLogRec> mlog =reader.getmlogs();
        showMLoginfo(mlog);
        list<LogRec> login = reader.getnomlogs();
        showLoginfo(login);

    }
    catch (exception& ex)
    {
        cout << ex.what()<< endl;
  //      return -1;

    }
}

void clientui2::on_pushButton_2_clicked()
{
    close();
}

//未匹配信息
void clientui2::showLoginfo(list<LogRec>& logs)
{

    for (list<LogRec>::iterator oit =
                logs.begin ();
            oit != logs.end (); ++oit)
{
   // cout << *oit << endl;
    LogRec log = *oit;
    QString str(log.logname);
    str += "    ";
    str += QString(log.logip);
    str += "    ";
    str += QString::number(log.pid);
    str += "    ";
    str += QString::number(log.logtime);
    str += "    ";
    ui->textEdit_2->append(str);

    }

}

void clientui2::showMLoginfo(list<MLogRec>& logs)
{
    for (list<MLogRec>::iterator oit =
                logs.begin ();
            oit != logs.end (); ++oit)
{
    cout << *oit << endl;
    MLogRec log = *oit;
    QString str(log.logname);
    str += "    ";
    str += QString(log.logip);
    str += "    ";
    str += QString::number(log.pid);
    str += "    ";
    str += QString::number(log.logintime );
    str += "    ";
    str += QString::number(log.logouttime );
    str += "    ";
    str += QString::number(log.durations );
    ui->textEdit->append(str);}
}

void clientui2::chTime()
{
    ui->lcdNumber->display(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}
