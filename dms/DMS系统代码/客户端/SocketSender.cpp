#include "SocketSender.h"
#include <iostream>
#include <list>
#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fstream>
#include <sys/socket.h>
#include <sstream>
using namespace std;
//构造函数
SocketSender::SocketSender(const string& failFile,
        short port,const string& ip):
    m_failFile(failFile),m_port(port),m_ip(ip)
{
   // m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
}
//析构函数
SocketSender::~SocketSender() throw() {}
//发送日志
void SocketSender::sendLog(list<MLogRec>& logs)throw (SendException)
{
    cout<<"发送开始..."<< endl;
    //读取失败的文件
    try{
    readFailFile(logs);}
    catch (ReadException& e1){
        cout<<"无法读取发送失败的文件"<<endl;
    }
    //连接服务器
    try {
    connectServer();
    }
    catch(SocketException& e2)
    {
       saveFailFile(logs);
    }
    //发送数据
    try {
    sendData(logs);
    }
    catch(SendException& e3)
    {
        saveFailFile(logs);
    }
    cout<<"发送结束..."<< endl;
}
//连接服务器
void SocketSender::connectServer() throw (SocketException)
{
    cout<<"连接服务器开始..."<< endl;
    m_sockfd = socket(AF_INET,SOCK_STREAM,0);
    //抛出网络异常
    if (m_sockfd == -1)
    throw SocketException();
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(m_port);
    addr.sin_addr.s_addr = inet_addr(m_ip.c_str());
    int ret = connect(m_sockfd,(struct sockaddr*)&addr,sizeof(addr));
    if (ret == -1)
    {
      perror("connect");
    }

    //发送数据例子
  /*  char buf[128]={};
    printf("input\n");
    scanf("%s",buf);
    ret = write(sockfd,buf,strlen(buf));
    if (ret == -1)
    {
      perror("write");
      return -2;

    }*/

   // return 0;

    cout<<"连接服务器结束..."<< endl;
}
//读发送失败的文件
void SocketSender::readFailFile(list<MLogRec>& logs) throw (ReadException)
{
    cout<<"读取失败文件开始..."<< endl;
    //创建输入流，以二进制的方式读取

         ifstream ifs (m_failFile.c_str(), ios::binary);
         if (!ifs)
         { throw ReadException();
             cout<< "读取错误"<<endl;
         }
     //定义一个空的匹配记录
     MLogRec log;
     //从发送失败的文件中读出记录先写到log中，再将节点插入到logs链表中
     //正常情况下读完，会到文件结尾
    ;
     while (ifs.read((char*)&log,sizeof(log)))
     {
        logs.push_front (log);
 //       ret = ifs.read((char*)&log,sizeof(log));
     }
      //如果没有到文件结尾，就抛出读取异常
    if (!ifs.eof ())
        throw ReadException ();
    //关闭输入流
        ifs.close ();
//删除生成的临时文件	unlink (m_failFile.c_str ());
    cout<<"读取失败文件结束..."<< endl;
}
//发送数据
void SocketSender::sendData(list<MLogRec>& logs)
throw (SendException)
{
    cout << "发送数据开始..." << endl;
    //当链表中的数据不为空的时候
    int cnt =0;
    while(!logs.empty())
    {

        //将头节点赋给log
      MLogRec   log=logs.front();
        //本地字节序转换成网络字节序
    //    log.logname=htonl(log.logname);
        log.pid=htonl(log.pid);
        log.logintime=htonl(log.logintime);
        log.logouttime=htonl(log.logouttime);
        log.durations=htonl(log.durations);
       // cout << log.logip << endl;
        //如果发送失败
     /*   if(send(m_sockfd,&log,sizeof(MLogRec),0)==-1)
         {
           //关闭socket描述符
             close(m_sockfd);
            //抛出发送异常
            throw SendException();
         }*/

        size_t total = 0;
        size_t len = sizeof(MLogRec);
        while (total != len)
        {
            ssize_t nb = send(m_sockfd,&log+total,len-total,0);
            total += nb;
        }

        //将发送出去的匹配记录删除，则剩余的即未发送成功的记录，将其写入发送失败的文件
        logs.pop_front();
        cnt ++ ;
    }
        //正常情况下，发送完成后关闭socket描述符
    close(m_sockfd);
    cout << "send_data records: " <<cnt << endl;
    cout << "发送数据完成。" << endl;
}
//保存发送失败的记录
void SocketSender::saveFailFile(list<MLogRec>& logs) throw (SaveException)
{
    cout<<"保存发送失败文件开始..." << endl;
    if(!logs.empty())
    {
        //创建输出流，二进制方式
        ofstream ofs(m_failFile.c_str(),
                     ios::binary);
        //如果创建输出流不存在，则抛出保存异常。
        if(! ofs)
            throw SaveException();
        //当匹配的日志记录链表不为空的时候
        while(!logs.empty())
        {
            //将未发送的日志记录写入文件中
            ofs.write((const char*) &logs.front(), sizeof(MLogRec));
            //写入后删除
            logs.pop_front();
        }
        //关闭输出流
        ofs.close();
    }
    cout<<"保存发送失败文件完成。" << endl;
}
