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
public:
    int n_low_x(int m, int n, int ta){
        int cnt = 0;
        int i = 1, j = n;
        while(i <= m && j >= 1){
            if(i*j > ta){
                j--;
            }
            else{
                cnt += j;
                i++;
            }
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n;
        if(hi == k){return hi;}
        //int sma = min(m, n), big = max(m, n);

        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            int cnt = n_low_x(m, n, mid);
            if(k > cnt){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return hi;
    }
};
void test(int m, int n){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            printf("%2d ", i*j);
        }
        printf("\n");
    }
}
int main()
{
    Solution sl;
    test(6, 6);
    //cout << sl.findKthNumber(2, 3, 6) << endl;
    //cout << sl.findKthNumber(45, 12, 471) << endl;//312
    //cout << sl.findKthNumber(3, 3, 5) << endl;
    cout << sl.findKthNumber(17452, 29185, 95573422) << endl;
    return 0;
}
