#include "Client.h"
#include <iostream>
using namespace std;
Client::Client(LogReader& reader,LogSender& sender):m_reader(reader),m_sender(sender)
{
}
void Client::dataMine(void) throw (ClientException)
{
    cout<<"数据挖掘开始..."<<endl;
    list<MLogRec>& logs = m_reader.readLog();
    m_sender.sendLog(logs);
    cout<<"数据挖掘结束..."<<endl;
}
/*
void Client::sendData(void) throw(ClientException)
{
    m_sender.sendLog(logs);
    cout<<"数据挖掘结束..."<<endl;
}
*/
