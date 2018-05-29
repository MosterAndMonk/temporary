//定义客户机类
#ifndef   _CLIENT_H
#define   _CLIENT_H
#include "LogReader.h"
#include "LogSender.h"
using namespace std;
class Client{

    private:
        //日志读取器
         LogReader&  m_reader;
         //日志发送器
         LogSender&  m_sender;
         //static list<MLogRec>& logs;
    public:
         //构造函数
         Client(LogReader& reader,LogSender& sender);
         //数据挖掘
         void dataMine(void)throw (ClientException);
         ////数据发送
         //void sendData(void)throw (ClientException);

};

#endif   //_CLIENT_H
