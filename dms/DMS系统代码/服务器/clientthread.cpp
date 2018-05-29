#include <iostream>
#include <unistd.h>
#include "clientthread.h"
#include "data.h"
#include <list>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "server.h"
using namespace std;
// 构造器
ClientThread::ClientThread (int connfd) :
    m_connfd (connfd) {}
    // 线程处理
void ClientThread::run(void)
{
  cout<<"clientthread start-------------"<<endl;
    cout << "接收到匹配日志记录开始" << endl;
    unsigned long long logs;
    for(logs=0; ;++logs)
    {
        bool flag = false;
        //接收到数据
        MLogRec log;
        //       if(recv(m_connfd,&log,sizeof(log), 0) > 0)
        ssize_t rlen = 0;
        for(ssize_t len = sizeof(MLogRec); len; len -= rlen)
        {
            rlen = recv(m_connfd, ((char*)&log) + sizeof(MLogRec) - len, len, 0);
            if(rlen <= 0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            //发送完成
            cout << "flag" << endl;
            break;
        }
        log.pid = ntohl(log.pid);   
        log.logintime = ntohl(log.logintime);
        log.logouttime = ntohl(log.logouttime);
        log.durations = ntohl(log.durations);
        logque << log;
    }
     cout << logs<<"接受记录数量"<< endl;
    cout << "clientthread finish-------------";
    cout << "接收到匹配日志记录结束" << endl;
    delete this;
}

