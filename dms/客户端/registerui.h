#ifndef REGISTERUI_H
#define REGISTERUI_H

#include <QMainWindow>

namespace Ui {
class registerui;
}

class registerui : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit registerui(QWidget *parent = 0);
    ~registerui();
    
private:
    Ui::registerui *ui;
};

#endif // REGISTERUI_H
