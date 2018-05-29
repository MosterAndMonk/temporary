#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <sys/stat.h>
#include <arpa/inet.h>
using namespace std;
#include "LogReader.h"

//构造函数
LogReader::LogReader(const string& logFile,const string& loginsFile):m_logFile(logFile),m_loginsFile(loginsFile)
{
}
list <MLogRec>& LogReader::getmlogs() {
    return copylog;
}
list <LogRec>& LogReader::getnomlogs()
{   readLoginsFile ();
    return m_logins;
}

//读取日志
list<MLogRec>& LogReader::readLog(void) throw (ReadException)
{
    cout << "读取日志文件开始..."<< endl;
    try
    {
        // 备份日志文件
        backup ();
    }
    catch (BackupException& e)
    {
      throw ReadException("备份文件失败");
    }

    try{
        // 读取有登入未登出的文件
        readLoginsFile ();
    }
    catch (ReadException& e)
    {
        throw ReadException("读取文件失败");
    }

     try {
        // 读取备份文件
        readBackupFile ();
     }
     catch (ReadException& e)
     {
          throw ReadException("读取备份文件异常");
     }

        // 匹配登入登出记录
        match ();

      try {
        // 保存有登入未登出的文件
        saveLoginsFile ();
    }
    catch (SaveException& ex)
    {
        throw ReadException ("保存文件异常");
    }

    cout << "读取日志文件结束..."<< endl;
    return m_logs;
}
//备份日志文件
void LogReader::backup(void) throw (BackupException)
{
    cout << "备份日志文件开始..."<< endl;
    string cmd("./backup.sh ");
    cmd += m_logFile;
    cmd += " ";
    time_t t = time(NULL);
    tm* p_tn = localtime(&t);
    int year = (p_tn->tm_year)+1900;
    int month = (p_tn->tm_mon)+1;
    int day = p_tn->tm_mday;
    int hour = p_tn->tm_hour;
    int minu = p_tn->tm_min;
    int sec = p_tn->tm_sec;
    char buf[32] = {'\0'};
    sprintf(buf, "%04d%02d%02d%02d%02d%02d", year, month, day, hour, minu, sec);
    m_backupFile = m_logFile+"."+buf;
    cmd += m_backupFile;
    system(cmd.c_str());
    cout << "备份日志文件结束..."<< endl;
}
//读取登入日志文件
void LogReader::readLoginsFile(void) throw(ReadException)
{
    cout << "读取登入文件开始..." << endl;
    //定义输入流，用二进制方式打开
    ifstream ifs (m_loginsFile.c_str (),
                  ios::binary);
    if (ifs)
    {
        LogRec log;                   //定义日志记录
        while (ifs.read ((char*)&log, sizeof (log)))
            //每次从文件中读出一条记录
            //将读出的记录压入登入记录中
            m_logins.push_back (log);
        //如果文件没有到达末尾，则会抛出异常
        if (! ifs.eof ())
            throw ReadException ();
        ifs.close ();                //关闭文件流
    }

    cout << "登入日志记录：" <<
         m_logins.size () << endl;
    cout << "读取登入文件完成。" << endl;
}
//读备份日志文件
void LogReader::readBackupFile(void) throw(ReadException)
{
    cout << "读取备份文件开始..." << endl;
    // 创建输入流，以二进制方式
    cout << m_backupFile.c_str() << endl;
    ifstream ifs (m_backupFile.c_str (),
                  ios::binary);
    if (!ifs)
        throw ReadException (
            "打开文件异常");
    // 计算记录条数
    struct stat st;
    if (stat (m_backupFile.c_str (), &st)==-1)
        throw ReadException (
            "无法获取备份文件大小");
    int records = st.st_size / 372;
    // 逐条读取记录
    for (int i = 0; i < records; ++i)
    {
        // 定位到记录开始
        ifs.seekg (i * 372, ios::beg);     //seekg函数用于设置输入文件流的文件流指针位置
        // 登录名
        char logname[32];
        ifs.read (logname, 32);
        // 登录进程ID
        ifs.seekg (36, ios::cur);
        pid_t pid;
        ifs.read ((char*)&pid, sizeof (pid));
        pid = ntohl (pid);
        // 登录类型：7-登入，8-登出
        short type;
        ifs.read ((char*)&type, sizeof(type));
        type = ntohs (type);
        // 登入登出时间
        ifs.seekg (6, ios::cur);
        long logtime;
        ifs.read ((char*)&logtime,
                  sizeof (logtime));
        logtime = ntohl (logtime);
        // 登录IP长度
        ifs.seekg (24, ios::cur);
        short len;

        ifs.read ((char*)&len, sizeof (len));
        len = ntohs (len);
      //  cout <<"ipLength =" <<len<< endl;
        // 登录IP或机器名
        char logip[len+1];
        ifs.read (logip, len);
        logip[len] = '\0';
        // 登录名以.开头的用户是ssh/telnet
        // 软件建立的伪用户，丢弃之
     //   cout << logip << endl;
        if (logname[0] != '.')
        {
            LogRec log;
            strcpy (log.logname, logname);
            strcpy (log.logip, logip);
            log.pid = pid;
            log.logtime = logtime;
            if (type == 7) // 登入记录
                m_logins.push_back (log);
            else if (type == 8) // 登出记录
                m_logouts.push_back (log);
           // cout << log.logip << endl;
        }
    }
    ifs.close ();
//    cout << "登入日志记录："
//         << m_logins.size () << endl;
//    cout << "登出日志记录："
//         << m_logouts.size () << endl;
//    cout << "读取备份文件完成。" << endl;
}
//匹配登入登出的记录
void LogReader::match (void)
{
    cout << "匹配登入登出开始..." << endl;
    //登出记录
    for (list<LogRec>::iterator oit =
                m_logouts.begin ();
            oit != m_logouts.end (); ++oit)
        // 登入记录
        for (list<LogRec>::iterator iit =
                    m_logins.begin ();
                iit != m_logins.end (); ++iit)
        {
            // 登录名一致
            if (! strcmp (iit->logname, oit->logname) &&
                    // 登录IP一致
                    ! strcmp (iit->logip,  oit->logip) &&
                    // 登录进程ID一致
                    iit->pid == oit->pid)
            {
                MLogRec log = {"","",0,0,0,0};
                strcpy (log.logname, oit->logname);//用户名写入
              //  cout << log.logname <<" " ;
                strcpy (log.logip, oit->logip);//ip写入
              //  cout << log.logip << " " ;
                log.pid = oit->pid; //pid写入
               // cout << log.pid<< " ";
                log.logintime = iit->logtime;//匹配登入时间
              // cout << log.logintime << " ";
                log.logouttime= oit->logtime; //匹配登出时间
               // cout << log.logouttime << " ";
                log.durations = log.logouttime - log.logintime;//登陆时长
              //  cout << log.durations << endl;
              //   cout << log <<endl;
                //将该记录压入匹配好的日志记录链表中
                m_logs.push_back (log);
                //删除已经匹配的登入记录
                m_logins.erase (iit);
                break;

            }
        }

    cout << "匹配日志"<< m_logs.size ()<<"记录" << endl;
    copylog =m_logs;
    cout << "匹配登入登出完成。" << endl;
}
void LogReader::saveLoginsFile (void) throw (SaveException)
{
    cout << "保存登入文件开始..." << endl;
    if (! m_logins.empty ())
    {
        ofstream ofs (m_loginsFile.c_str (),//定义一个ofs，返回m_loginsFile的地址
                      ios::binary); //二进制
        if (! ofs) throw SaveException ();//如果ofs不存在，抛出异常
        while (! m_logins.empty ())
        {
            ofs.write ((const char*) &m_logins.front (), sizeof (LogRec));
            m_logins.pop_front ();//删除头节点数据
        }
        ofs.close ();
    }
    cout << "保存登入文件完成。" << endl;
}
