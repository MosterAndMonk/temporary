#include "server.h"

using namespace std;
Server::Server(LogDao& dao,short port,const string& ip):m_store(dao),m_socket(port,ip){}

void Server::dataMine(void)
{
   m_store.start();
   m_socket.acceptClient();
}
