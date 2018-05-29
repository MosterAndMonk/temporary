#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QDialog>
class QLCDNumber;
class QTimer;
class MyDialog : public QDialog
{
  Q_OBJECT
public:
  explicit MyDialog(QWidget *parent = 0);
private:
  QLCDNumber *lcd;
  QTimer *timer;
};
#endif // MYDIALOG_H
