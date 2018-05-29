    #include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Solution
{
public:
    int LastRemaining_Solution_0(int n, int m)
    {
        if(n < 1 || m < 1){
            return -1;
        }
        if(n == 1)
            return 0;
        int curN = 0, curM = 0;
        int n_all = n;
        bool *signN = new bool[n];
        memset(signN, 0, sizeof(bool)*n);

        while(n_all > 1)
        {
            if(!signN[curN])
            {
                if(curM == m-1)
                {
                    signN[curN] = true;
                    n_all--;
                    //cout << curN << endl;
                }
                curM ++;
                curM %= m;
            }
            curN ++;
            curN %= n;
        }
        while(signN[curN]){
            curN++;
            curN %= n;
        }
        delete [] signN;
        return curN;
    }
    int LastRemaining_Solution_1(int n, int m)
    {
        if(n < 1 || m < 1){
            return -1;
        }
        if(n == 1)
            return 1;
        int curN = 1, curM = 1;
        int n_all = n;
        bool *signN = new bool[n+1];
        memset(signN, 0, sizeof(bool)*(n+1));
        signN[0] = true;

        while(n_all > 1)
        {
            if(!signN[curN])
            {
                if(curM == m)
                {
                    signN[curN] = true;
                    n_all--;
                    //cout << endl << curN << endl;
                }
                curM ++;
                if(curM == (m+1))
                    curM = 1;
            }
            curN ++;
            if(curN == (n+1))
                curN = 1;
        }
        while(signN[curN]){
            curN++;
            if(curN == (n+1))
                curN = 1;
        }
        delete [] signN;
        return curN;
    }
    int LastRemaining_Solution(int n, int m)
    {
        if(n <= 0 || m <= 0){
            return -1;
        }
        int survived = 0;
        for(int i = 2; i <= n; i++){
            survived = (survived + m)%i;
        }
        return survived;
    }
};

int main()
{
    Solution sl;
    /*
    for(double n = 1; n < 65; n++){
        cout << log(n) / log(2.0) << " ";
    }cout << endl;
    */
    for(int n = 1; n < 129; n++){
        int m = 2;
        //for(int m = 0; m < 10; m++){
            cout << " n=" ;
            printf("%2d", n);
            cout << " m=" << m;
            cout << " f(n)=";
            printf("%2d", sl.LastRemaining_Solution(n, m));

            double pm = (log(n*1.0) / log(m*1.0));
            cout << " logm(n)=";
            cout << (int)pm;

            cout << " functionV=";
            cout << (n - pow(m, (int)pm)) * m + 1;
            cout << endl;
        //}
    }

    return 0;
}
