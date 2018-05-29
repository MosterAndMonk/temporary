#ifndef _SERVERSOCKET_H
#define _SERVERSOCKET_H
#include <string>
#include "except.h"
using namespace std;

// 服务器套接字类
 class ServerSocket {
 public:
  // 构造器
      ServerSocket (short port,const string& ip
          )
          throw (SocketException);
 // 等待客户机连接
      void acceptClient (void)
      throw (SocketException);
 private:
          int m_sockfd; // 侦听套接字
                                
 };        
#endif // _SERVERSOCKET_H

