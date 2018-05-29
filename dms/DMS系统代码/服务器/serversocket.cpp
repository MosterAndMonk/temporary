#include <iostream>
#include "serversocket.h"
#include "clientthread.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

// 构造器
ServerSocket::ServerSocket (short port,const string& ip)
    throw (SocketException) 
{
    cout << "初始化服务器开始..." << endl;
    m_sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(m_sockfd == -1)
        throw SocketException("套接字创建失败");
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr =inet_addr(ip.c_str());
    cout << "--------------------------" << endl;
    cout << ip << endl;
    cout << port << endl;
    cout << "--------------------------" << endl;
    int ret = bind(m_sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if(-1 == ret)
        throw SocketException("绑定失败");
    cout << "初始化服务器完成。" << endl;
} 
// 等待客户机连接
 void ServerSocket::acceptClient (void)
        throw (SocketException) 
{
    cout << "等待客户机连接..." << endl;
    listen(m_sockfd, 100);
    struct sockaddr_in from;
    while(1)
    {
        socklen_t len = sizeof(from);
        int fd = accept(m_sockfd, (struct sockaddr*)& from, (socklen_t *)&len);
        /*
        ClientThread ct(fd);
        ct.start();
        */
        (new ClientThread(fd))->start();

	//try{
        //}catch()
    }
    close(m_sockfd);
}
