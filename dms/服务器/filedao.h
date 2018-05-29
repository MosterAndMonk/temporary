#ifndef _FILEDAO_H
#define _FILEDAO_H
#include <fstream>
#include "logdao.h"
#include <list>
using namespace std;
//文件数据访问对象类
class FileDao : public LogDao {
    public:
    // 构造器
     FileDao (const string& path)
     throw (DBException);
     ~FileDao (void);
     // 插入
     void insert (const MLogRec& log)
     throw (DBException);

     list<MLogRec>& readDaoFile(void);

    private:
        ofstream m_ofs; // 输出文件流
        ifstream m_ifs; //输入文件流
};

#endif  //_FILEDAO_H

