#include "registerui.h"
#include "ui_registerui.h"

registerui::registerui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registerui)
{
    ui->setupUi(this);
}

registerui::~registerui()
{
    delete ui;
}
