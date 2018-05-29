#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

class Solution
{
public:
    double dp[200][200];

    double largestSumOfAverages(vector<int>& A, int K)
    {
        memset(dp, 0, sizeof(double)*200*200);
        int n = A.size();

        double cur = 0.0;
        for(int i = 0; i < n; i++){
            cur += A[i];
            dp[i+1][1] = cur / (i+1);
        }

        return dfs(A, n, K);
    }

    double dfs(const vector<int>& A, int n, int K){
        if(dp[n][K] != 0){
            return dp[n][K];
        }
        double cur = 0.0;
        for(int i = n-1; i > 0; i--){
            cur += A[i];
            double nn = dfs(A, i, K-1);
            dp[n][K] = max(dp[n][K], nn + cur/(n-i));
            //dp[n][K] = max(dp[n][K], dfs(A, i, K-1) + cur/(n-i));
            printf("dp[%d, %d]=%g + %g = %g\n", n, K, nn, cur/(n-i), dp[n][K]);
        }
        return dp[n][K];
    }
    double avg(vector<int>& A, int s, int e)
    {
        double sum = 0.0;
        for(int i = s; i <= e; i++)
        {
            sum += A[i];
        }
        return (sum / (e-s+1));
    }

    double largestSumOfAverages2(vector<int>& A, int K)
    {
        int n = A.size();

        vector<int> C(K, 0);
        vector<double> dp(K+1, 0);

        //dp[1] = A[0];
        int Ci_1 = -1, Ci = 0;

        for(int i = 1; i <= K; i++)
        {
            for(int j = Ci_1+1; j < n-(K-i); j++)
            {
                double cur = ((Ci_1+1)?dp[i-1]:0)+avg(A, Ci_1+1, j);

                if(dp[i] < cur)
                {
                    Ci = j;
                    dp[i] = cur;
                }
                //cout <<"i=" <<i <<" Ci_1=" << Ci_1 << " "<< dp[i] << endl;
            }
            Ci_1 = Ci;
        }
        return dp[K];
    }
    /************************************************************/
    double largestSumOfAverages_fail(vector<int>& A, int K)
    {
        double max_avg = 0.0;
        for(int i = 0; i < A.size(); i++)
        {
            max_avg = max((double)A[i], max_avg);
        }
        double sum = 0.0;
        int cut = K-1;

        double cur_sum = 0.0;
        int cnt = 0;

        int i = 0;
        while(cut >= 0 || i < A.size())
        {
            if(i < A.size() && (cur_sum + A[i]) <= max_avg && cut <=(int)(A.size() - i - 1))
            {
                cur_sum += A[i];
                cnt ++;
                i++;
            }
            else
            {
                //max_avg = max(cur_avg, max_avg);
                sum += cur_sum / (cnt);
                cout << cur_sum << " " << cnt << endl;
                cut --;
                cur_sum = 0.0;
                cnt = 0;
            }
        }
        return sum;
    }
};

int main()
{
    Solution sl;
    int a[5] = {9, 1, 2, 3, 9};
    vector<int> A((&a[0]), (&a[0])+5);
    cout << sl.largestSumOfAverages(A, 3);
    /*
        int a[7] = {1,2,3,4,5,6,7};
        vector<int> A((&a[0]), (&a[0])+7);
        cout << sl.largestSumOfAverages(A, 4);



        int a[3] = {1, 2, 3};
        vector<int> A((&a[0]), (&a[0])+3);


        cout << sl.largestSumOfAverages(A, 3);
            */
    return 0;
}

/*
Input:
[4,1,7,5,6,2,3]
4
Output:
15.25
Expected:
18.16667
*/
