#ifndef    _CONSOLESENDER_H
#define    _CONSOLESENDER_H
#include <list>
#include "data.h"
#include "except.h"
#include <iostream>
#include "LogSender.h"
class ConsoleSender:public LogSender
{
 public :
     void sendLog(list<MLogRec>& logs) throw (SendException);
};

#endif  //_CONSOLESENDER_H
