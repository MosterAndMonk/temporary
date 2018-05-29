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
    //map<int, int> m;
public:
    int n_low_x(vector<int>& nums, int x){
        if( x < 0 ){
            return 0;
        }
        /*
        if(m.find(x) != m.end()){
            return m[x];
        }
        */

        int n = nums.size();
        int cnt = 0;
        int d = 1;
        for(int i = 0; i + d < n; i++){
            while(i + d < n && (nums[i+d] - nums[i]) <= x){
                d++;
            }
            cnt += d-1;
            d = 1;
        }

        //m[x] = cnt;
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int lo = 0;
        int hi = nums[n-1]-nums[0];
        while(lo < hi){
            int mi = lo+(hi-lo)/2;
            int cnt = 0, d = 1;
            for(int i = 0; i + d < n; i++){
                while(i+d < n && (nums[i+d]-nums[i]) <= mi){
                    d++;
                }
                cnt += d-1;
                d = 1;
            }
            //    n_low_x(nums, mi);
            if(k > cnt){
                lo = mi+1;
            }
            else{
                hi = mi;
            }
        }
        return hi;
    }
};

int main()
{
    Solution sl;
    int a[3] = {1, 3, 1};
    vector<int> a_n(&a[0], &a[0]+3);
    cout << sl.smallestDistancePair(a_n, 1);
    /*


        int a[3] = {1, 1, 1};
    vector<int> a_n(&a[0], &a[0]+3);
    cout << sl.smallestDistancePair(a_n, 2);
    */


    return 0;
}
