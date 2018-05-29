// 实现存储线程类
#include <iostream>
#include "storethread.h"
#include "oracledao.h"
using namespace std;

// 构造器
StoreThread::StoreThread (LogDao& dao) :
    m_dao (dao) {}
// 线程处理
void StoreThread::run (void)
{
    MLogRec log;
    while(1)
    {
        oracledao nd;
        //cout << "storethread start---------------"<<endl;
        //cout << "将日志记录中的数据取出：" << endl;
        logque >> log ;
        //cout << log;
        nd.dbinsert(log);
        m_dao.insert(log);
        //cout << "storethread finish---------------"<< endl;
    }
}

