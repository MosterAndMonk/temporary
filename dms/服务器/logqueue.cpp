#include <iostream>
#include "logqueue.h"
using namespace std;
LogQueue logque;
list<MLogRec> LogQueue::myLog;
/*
bool LogQueue::myEmpty()
{
    return m_logs.empty();
}
*/
LogQueue::LogQueue()
{
    m_mutex = PTHREAD_MUTEX_INITIALIZER;
    m_cond = PTHREAD_COND_INITIALIZER;
   //这个条件表示队列不空的时候使用
}

LogQueue& LogQueue::operator<<(const MLogRec& log)
{
    pthread_mutex_lock(&m_mutex);
    m_logs.push_back(log);
    pthread_cond_signal(&m_cond);
    pthread_mutex_unlock(&m_mutex);
    return *this;
}

LogQueue& LogQueue::operator>>(MLogRec& log)
{
    pthread_mutex_lock(&m_mutex);
    if(m_logs.empty())
        pthread_cond_wait(&m_cond, &m_mutex);
    log = m_logs.front();
    myLog.push_back(log);
    //
    m_logs.pop_front();
    //
    pthread_mutex_unlock(&m_mutex);
    return *this;
}
