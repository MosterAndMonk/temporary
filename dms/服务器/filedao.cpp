//实现文件数据访问对象类
#include <iostream>
#include "filedao.h"
using namespace std;
//构造器
FileDao::FileDao (const string& path)
     throw (DBException)
     {
        cout << "打开文件dao开始..." << endl;
        m_ofs.open(path.c_str(),ios::app);
        m_ifs.open(path.c_str (), ios::binary);
      if(!m_ofs)
          throw DBException("无法打开数据库");
       cout << "打开文件dao完成。" << endl;
     }
FileDao::~FileDao (void) 
    {
        cout << "关闭文件dao开始..." << endl;
        m_ofs.close();
        cout << "关闭文件dao完成。" << endl;
    }
//插入
void FileDao::insert (const MLogRec& log)
        throw (DBException) 
     {
          //cout << "插入数据到文件开始..." << endl;
          m_ofs << log << endl;
          //cout << "插入数据到文件完成。" << endl;
     }
//读dao文件
list<MLogRec>& FileDao::readDaoFile(void)
{
    cout << "读取登入文件开始..." << endl;
    //定义输入流，用二进制方式打开
    list <MLogRec> logs;
    if (m_ifs)
    {
        MLogRec log; //定义日志记录
        int cnt = 0;
        while (m_ifs.read ((char*)&log, sizeof (log)))
            //每次从文件中读出一条记录
            //将读出的记录压入登入记录中
{
            logs.push_back (log);
            cnt++;
 }       cout << "从filedao.txt中取出log并且"<<cnt <<endl;
        //如果文件没有到达末尾，则会抛出异常
      /* if (! m_ifs.eof ())
          throw Exception ();*/
        m_ifs.close ();             //关闭文件流
    }

    cout << "登入日志记录：" <<
         logs.size () << endl;
    cout << "读取登入文件完成。" << endl;
    return logs;
}
