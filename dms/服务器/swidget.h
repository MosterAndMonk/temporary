#ifndef SWIDGET_H
#define SWIDGET_H

#include <QMainWindow>
#include "table.h"
#include "q_thread.h"
#include "data.h"
namespace Ui {
class swidget;
}

class swidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit swidget(QWidget *parent = 0);
    ~swidget();

signals:
    void beLogs(MLogRec);

private slots:
    void on_start_clicked();
    void on_table_select_clicked();
    void on_send(MLogRec);
    void on_time();
    void on_file_select_clicked();    
    void on_pushButton_clicked();

private:
    Ui::swidget *ui;
    Table two;
    q_thread my_thread;
    QTimer* qtm;
};

#endif // SWIDGET_H
