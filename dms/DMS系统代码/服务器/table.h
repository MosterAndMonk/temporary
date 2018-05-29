#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QButtonGroup>
namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT
public:
    explicit Table(QWidget *parent = 0);
    ~Table();

private slots:
    void on_t_select_clicked();
    void on_t_close_clicked();
    void setYear();
    void setMonth();
    void setDay();

private:
    Ui::Table *ui;
    QSqlQueryModel *model;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    static QString sql_str;
    QButtonGroup dataSelect;
    int syear;
    int smonth;
    int sday;
};

#endif // TABLE_H
