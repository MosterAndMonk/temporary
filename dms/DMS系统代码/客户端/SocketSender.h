#ifndef    _SOCKETSENDER_H
#define    _SOCKETSENDER_H
#include "LogSender.h"
using namespace std;
class SocketSender:public LogSender
{

private:
    string m_failFile;
    short m_port;
    string m_ip;
    int m_sockfd;
    void connectServer(void) throw (SocketException);
    void readFailFile(list<MLogRec>& logs) throw(ReadException);
    void sendData(list<MLogRec>& logs)throw (SendException);
    void saveFailFile(list<MLogRec>& logs)throw (SaveException);
public :
    SocketSender(const string& failFile,short port,const string& ip);
    void sendLog(list<MLogRec> & logs) throw (SendException);
    ~SocketSender() throw();


};
#endif   //SOCKETSENDER_H
