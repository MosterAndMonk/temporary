#include <iostream>
#include <algorithm>

using namespace std;

void printv(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    const static int INF = 0x7fffffff;
    int GetUglyNumber_Solution(int index)
    {
        if(index < 1){
            return 0;
        }
        int facts[3] = {2, 3, 5};

        int uglyNumber[index][4];
        int start = 0, cur = 0;
        uglyNumber[cur][0] = 1;
        for(int k = 0; k < 3; k++)
        {
            uglyNumber[cur][k+1] = uglyNumber[cur][0] * facts[k];
        }
        for(int cur = start; cur < index; )
        {
            int minV = INF;
            int minx = 0, miny = 0;
            for(int i = start; i <= cur; i++)
            {
                for(int j = 1; j < 4; j++)
                {
                    if(uglyNumber[i][j] > uglyNumber[cur][0]){
                        if(uglyNumber[i][j] < minV){
                            minV = uglyNumber[i][j];
                            minx = i;
                            miny = j;
                        }
                    }
                }
                if(uglyNumber[start][3] == INF){
                    start = start + 1;
                }
            }

            cur = cur + 1;
            uglyNumber[cur][0] = minV;
            uglyNumber[minx][miny] = INF;
            for(int k = 0; k < 3; k++)
            {
                uglyNumber[cur][k+1] = uglyNumber[cur][0] * facts[k];
            }
        }
        return uglyNumber[index-1][0];

    }
};

int main()
{

    Solution sl;
    while(1)
    {
        int n;
        cin >> n;
        cout << sl.GetUglyNumber_Solution(n) << endl;
    }

    const int INF = 0x7fffffff;

    cout << max(INF, 7) << endl;
    return 0;
}
