//实现线程类
#include <pthread.h>
#include <iostream>
#include "logthread.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
using namespace std;
//构造函数
//LogThread::LogThread(void){}
// 启动线程
 void LogThread::start (void)
  throw (ThreadException)
{       
    cout << "启动线程开始..." << endl;
    pthread_t tid;
    int error = pthread_create(&tid,NULL,run,this);
    if(error)
    {
        printf("%s\n",strerror(error));
    }
    cout << "启动线程完成。" << endl;
}
// 线程过程
// 把this指针通过参数传给arg
 void* LogThread::run(void* arg)
 {
  //   cout << "hello" << endl;
//使线程处于分离状态，一旦处于分离，该线程终止时将被回收     
 pthread_detach(pthread_self());
 //获取子类对象，通过子类对象调用run
 (static_cast<LogThread*>(arg))->run();
 return NULL;
 }
                            

