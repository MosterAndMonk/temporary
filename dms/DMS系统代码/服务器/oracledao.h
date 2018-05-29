#ifndef ORACLEDAO_H
#define ORACLEDAO_H

#include <data.h>
#include <QSqlDatabase>
class oracledao
{
public:
    void dbinsert(MLogRec& log);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};

#endif // ORACLEDAO_H
