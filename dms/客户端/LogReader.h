#ifndef		_LOGREADER_H
#define 	_LOGREADER_H
#include "data.h"
#include "except.h"
#include <list>
using namespace std;
class LogReader{

private:
     string m_logFile; //日志文件
     string m_loginsFile;  //登入日志文件
     string m_backupFile;  //备份日志文件
     list<LogRec> m_logins;  //登入记录链表
     list<LogRec> m_logouts; // 登出记录链表
     list<MLogRec> m_logs;   //匹配好的记录链表


     void backup(void) throw (BackupException);
     void readLoginsFile(void) throw (ReadException);
     void readBackupFile(void) throw (ReadException);
     void match(void);
     void saveLoginsFile(void) throw (SaveException);
public:
     LogReader(const string& logFile,const string& loginsFile);  //构造函数
     list <MLogRec>& readLog() throw (ReadException); //读取匹配记录
     list <MLogRec>& getmlogs();
     list <LogRec>& getnomlogs();
     list <MLogRec> copylog;
};

#endif		// _LOGREADER_H
