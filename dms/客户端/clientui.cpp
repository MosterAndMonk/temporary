#include "clientui.h"
#include "ui_clientui.h"
#include <QDebug>
#include <qdialog.h>
#include <QSqlQuery>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QtSql>
#include <QFile>
clientui::clientui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientui)
{

    db.setHostName("localhost");
    db.setDatabaseName("dms");
    db.setUserName("root");
    db.setPassword("123456");
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->register_2,SIGNAL(clicked()),this,SLOT(register_u()));
    ui->password->setEchoMode(QLineEdit::Password);
}

clientui::~clientui()
{
    delete ui;
}

void clientui::on_pushButton_2_clicked()
{
    close();
}

void clientui::on_pushButton_clicked()
{
    QString un =ui->username->text();
    QString pwd =ui->password->text();
    QString er=ui->error->text();
    if(db.open()){
    QSqlQuery query;
    query.exec("select *from dms.people");
    while(query.next())
    {
        if(un ==query.value(1) && pwd ==query.value(2))
            {
                two.show();
                this->hide();
            }else{
                ui->error->setText("用户名或密码错误，请重新输入!");
                ui->username->clear();//清空用户名输入框
                ui->password->clear();//清空密码输入框
                ui->username->setFocus();//将光标转到用户名输入框
            }
    }}

}
void clientui::register_u()
{
   //新的对话框
    QDialog *dialog = new QDialog;
    dialog->setGeometry(400,400,400,300);
    dialog->show();
   //用户名
    QLineEdit *user =new QLineEdit(dialog);
    user->setGeometry(155,60,181,27);
    user->show();
   //标签
    QLabel *lab = new QLabel(dialog);
    lab->setGeometry(55,23,120,100);
    lab->setText("输入用户名");
    lab->show();
   //密码
    QLineEdit *pw =new QLineEdit(dialog);
    pw->setGeometry(155,120,181,27);
    pw->show();
    pw->setEchoMode(QLineEdit::Password);
    //标签
    QLabel *lab_1 = new QLabel(dialog);
    lab_1->setGeometry(55,83,120,100);
    lab_1->setText("输入密码");
    lab_1->show();
   //标签
    QLabel *lab_2 = new QLabel(dialog);
    lab_2->setGeometry(55,143,150,100);
    lab_2->setText("请确认密码");
    lab_2->show();

   //密码2
    QLineEdit *pw_1 =new QLineEdit(dialog);
    pw_1->setGeometry(155,180,181,27);
    pw_1->show();
    pw_1->setEchoMode(QLineEdit::Password);

     //注册按钮
    QPushButton *btn = new QPushButton("注册",dialog);
    btn->setGeometry(70,230,70,25);
     btn->show();
   //取消按钮
     QPushButton *btn_1 = new QPushButton("取消",dialog);
     btn_1->setGeometry(250,230,70,25);
      btn_1->show();
     QHBoxLayout *layout= new QHBoxLayout;
      dialog->setLayout(layout);
      //绑定按钮
      connect(btn,SIGNAL(clicked()),dialog,SLOT(accept()));
      connect(btn_1,SIGNAL(clicked()),dialog,SLOT(reject()));

      //点击确定后将数据写入文件
      if (dialog->exec()==QDialog::Accepted)
      {
          QString u = user->text();
          QString p = pw->text();
          QString p1 =pw_1->text();
          if (p==p1)
          {
              if(db.open())
              {
                  QSqlQuery query;
                  query.exec("INSERT INTO dms.people(uname, upass) VALUES ('"+u+"','"+p+"')");
                  QMessageBox *qmb = new QMessageBox;
                  qmb->setGeometry(200,200,700,700);
                  qmb->setText("注册成功!");
                  qmb->show();
              }
          }else
          {
              QMessageBox *qmb = new QMessageBox;
              qmb->setGeometry(200,200,500,200);
              qmb->setText("两次密码不相同\r\n  请重新注册!");
              qmb->show();
          }
}
}
