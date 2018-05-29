#include "oracledao.h"
#include "data.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


void oracledao::dbinsert(MLogRec& log)
{
    //数据库连接
    db.setHostName("localhost");
    db.setDatabaseName("dms");
    db.setUserName("root");
    db.setPassword("123456");
    //MLogRec log;
    QString str1 = QString(QLatin1String(log.logname));//字符转换
    QString str2 = QString(QLatin1String(log.logip));
    QString spid =QString::number(log.pid);
    QString sin =QString::number(log.logintime);
    QString sout =QString::number(log.logouttime);
    QString sdu =QString::number(log.durations);//字符转换
    if (db.open())
    {
        QSqlQuery query(db);//将数据存入数据库
        query.exec("insert into dms.MLogRec(logname,logip,pid,logintime,logouttime,durations) values('"+str1+"','"+str2+"','"+spid+"','"+sin+"','"+sout+"','"+sdu+"')");
    }
}
