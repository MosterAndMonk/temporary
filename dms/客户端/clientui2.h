#ifndef CLIENTUI2_H
#define CLIENTUI2_H
#include <QDialog>
#include <QMainWindow>
#include <list>
#include "data.h"
#include "Client.h"
using namespace std;
namespace Ui {
class clientui2;
}

class clientui2 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit clientui2(QWidget *parent = 0);
    ~clientui2();
    void showMLoginfo(list<MLogRec>& logs);
    void showLoginfo(list<LogRec>& logs);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void chTime();
private:
    Ui::clientui2 *ui;
};

#endif // CLIENTUI2_H
