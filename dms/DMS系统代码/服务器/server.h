//声明服务器类
#ifndef  _SERVER_H
#define  _SERVER_H
#include <string>
#include "serversocket.h"
#include "storethread.h"
#include <list>
#include "data.h"
using namespace std;
class Server
{
    private:
        StoreThread m_store;
        ServerSocket m_socket;
    public:
        Server(LogDao& dao,short port,const string& ip);
        void dataMine(void);
};



#endif   //_SERVER_H

