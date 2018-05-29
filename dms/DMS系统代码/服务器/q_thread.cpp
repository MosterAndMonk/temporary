#include "q_thread.h"
#include "swidget.h"
#include "server.h"
#include "filedao.h"
#include "oracledao.h"
q_thread::q_thread(QObject *parent) :
    QThread(parent)
{

}
void q_thread::run()
{
    //emit(send_text("hello world !"));
    sleep(1);
    //ui->mes->setText("等待客户机连接!");
    FileDao dao("./filedao.txt");
// //   OracleDao dao("username","123456");
    Server server(dao,2004,"127.0.0.1");
    server.dataMine();
}
