#include <QApplication>
#include "clientui.h"
#include "clientui2.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QTextCodec>
using namespace std;

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dms");
    db.setUserName("root");
    db.setPassword("123456");
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
        db.lastError().text());
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    string cmd("./reset.sh");
    system(cmd.c_str());
    QApplication a(argc, argv);
    clientui w;
    w.show();

    return a.exec();
}

