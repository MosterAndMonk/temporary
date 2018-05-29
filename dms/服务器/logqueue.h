#ifndef _LOGQUEUE_H
#define _LOGQUEUE_H
#include <string>
#include <list>
#include "data.h"
using namespace std;
class LogQueue
{
    public: 
     LogQueue();
     LogQueue& operator<<(const MLogRec& log);
     LogQueue& operator>>(MLogRec& log);
     static list<MLogRec> myLog;
     //bool myEmpty(void);
    private:
           pthread_mutex_t  m_mutex;
           pthread_cond_t   m_cond;
           list<MLogRec>    m_logs;

};
extern LogQueue logque;
#endif   //_LOGQUEUE_H

