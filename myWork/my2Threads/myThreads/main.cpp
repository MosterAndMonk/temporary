#include <iostream>
#include <windows.h>
#include <process.h>
#include <cstdio>

using namespace std;

class ThreadX{
private:
    int loopStart;
    int loopEnd;
    int dispFrequency;
public:
    string threadName;

    ThreadX( int startValue, int endValue, int frequency ):loopStart(startValue),loopEnd(endValue), dispFrequency(frequency){

    }

    static unsigned __stdcall ThreadStaticEntryPoint(void* pThis){
        ThreadX *pthX = (ThreadX*)pThis;
        pthX->ThreadEntryPoint();

        return 1;
    }

    void ThreadEntryPoint(){
        for(int i = loopStart; i <= loopEnd; i++){
            if(i % dispFrequency == 0){
                printf("%s: i = %d\n", threadName.c_str(), i);
            }
        }
        printf("%s thread terminating\n", threadName.c_str());
    }
};

int main()
{
    ThreadX* o1 = new ThreadX(0, 10000, 2000);

    HANDLE hth1;
    unsigned uiThread1ID;
    hth1 = (HANDLE)_beginthreadex(NULL,
                                  0,
                                  ThreadX::ThreadStaticEntryPoint,
                                  o1,
                                  CREATE_SUSPENDED,
                                  &uiThread1ID);
    if(hth1 == 0)
        printf("Failed to create thread1\n");

    DWORD dwExitCode;

    GetExitCodeThread(hth1, &dwExitCode);
    printf("initial thread1 1 exit code = %u\n", dwExitCode);

    o1->threadName = "t1";


    ThreadX* o2 = new ThreadX(-1000000, 0, 2000);

    HANDLE hth2;
    unsigned uiThread2ID;
    hth2 = (HANDLE)_beginthreadex(NULL,
                                  0,
                                  ThreadX::ThreadStaticEntryPoint,
                                  o2,
                                  CREATE_SUSPENDED,
                                  &uiThread2ID);
    if(hth2 == 0)
        printf("Failed to create thread2\n");

    GetExitCodeThread(hth2, &dwExitCode);
    printf("initial thread 2 exit code = %u\n", dwExitCode);

    o2->threadName = "t2";

    ResumeThread(hth1);

    ResumeThread(hth2);

    WaitForSingleObject(hth1, INFINITE);

    WaitForSingleObject(hth2, INFINITE);

    GetExitCodeThread(hth1, &dwExitCode);
    printf( "thread 1 exited with code %u\n", dwExitCode );
    GetExitCodeThread( hth2, &dwExitCode );
    printf( "thread 2 exited with code %u\n", dwExitCode );

    CloseHandle( hth1 );
    CloseHandle( hth2 );

    delete o1;
    o1 = NULL;

    delete o2;
    o2 = NULL;

    printf("Primary thread terminating.\n");
    return 0;
}
