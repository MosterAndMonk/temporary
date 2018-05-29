#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
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
};

int main()
{
    Solution sl;
    for(int n = 2; n < 10; n++){
        for(int m = 0; m < 10; m++){
            cout << " n=" << n << " m=" << m;
            cout << " ans=";
            cout << sl.LastRemaining_Solution(n, m);
            cout << endl;
        }
    }

    return 0;
}
