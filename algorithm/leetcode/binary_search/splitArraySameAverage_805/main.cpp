#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

class Solution {
    bool is_exist(vector<int>& A, int sum, int cnt, int cur_i, int cur_sum, int cur_cnt){
        if(cur_cnt == cnt){
            return cur_sum == sum;
        }

        for(int i = cur_i; i < A.size(); i++){
            if(cur_sum + A[i] <= sum){
                if(is_exist(A, sum, cnt, i+1, cur_sum+A[i], cur_cnt+1)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        if(n <= 1){
            return false;
        }
        else if(n == 2 && A[0] != A[1]){
            return false;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
        }
        double avg = sum * 1.0 /n;
        for(int i = 0; i < n; i++){
            if( (sum-A[i])*1.0 / (n-1) < (avg)/2 ){
                return false;
            }
        }
        for(int i = 1; i <= n/2; i++){
            if(sum * i % n == 0){
                if(is_exist(A, sum * i / n, i, 0, 0, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{

    int a[30] = {9988,32,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
    vector<int> A(&(a[0]), &(a[0])+30);
/*
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> A(&(a[0]), &(a[0])+8);
    int a[10] = {2,0,5,6,16,12,15,12,4};
    vector<int> A(&(a[0]), &(a[0])+10);
        */
    Solution sl;
    cout << sl.splitArraySameAverage(A);
    return 0;
}
/*
[2,0,5,6,16,12,15,12,4]
9990,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30
[9990
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30
30]
*/
