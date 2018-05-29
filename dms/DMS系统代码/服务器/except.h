//服务器异常类
#ifndef    _EXCEPT_H
#define    _EXCEPT_H
#include <exception>
#include <iostream>
#include <string>
using namespace std;
class ServerException: public exception
{
   private: 
       string m_msg;
   public :
       ServerException(void):m_msg("服务器异常") {}
       ServerException(const string& msg):m_msg("服务器端异常："){
         m_msg= m_msg+msg;
         }

       ~ServerException(void) throw(){}
       const char* what(void) const throw() 
       {  
           return m_msg.c_str();
       }


};

class SocketException:public ServerException
{
   public:
    SocketException(void):ServerException("网络通信失败"){}
     SocketException(const string& msg):ServerException(msg){
      }                     
};

class DBException:public ServerException
{
    public:
      DBException(void):ServerException("访问数据库失败"){}
      DBException(const string& msg):ServerException(msg){

      }

};

class ThreadException: public ServerException
{
   public:
    ThreadException(void) :ServerException("创建线程失败"){}
     ThreadException(const string& msg):ServerException(msg){
     }
};
#endif     //  _EXCEPT_H

