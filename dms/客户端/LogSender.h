#ifndef _LOGSENDER_H
#define _LOGSENDER_H
#include <list>
#include "data.h"
#include "except.h"


class LogSender
{
   public:
       virtual ~LogSender(void){}
       virtual void sendLog(list<MLogRec>& logs) throw(SendException)=0;

};

#endif   //  _LOGSENDER_H
