#ifndef CLIENTUI_H
#define CLIENTUI_H


#include "clientui2.h"
#include <QSqlTableModel>
#include <QDialog>
namespace Ui {
class clientui;
}

class clientui : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit clientui(QWidget *parent = 0);
    ~clientui();
    
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void register_u();


private:
    Ui::clientui *ui;
    clientui2 two;
    QStringList username;
    QStringList password;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};

#endif // CLIENT_H
