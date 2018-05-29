#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    const int mod = 1000000007;
    int InversePairs(vector<int> data) {

        int l = data.size()-1;
        return mergeCount(data, 0, l);
    }

    int mergeCount(vector<int> cur, int s, int e){
        if(s == e){
            return 0;
        }
        int half = s + (e-s)/2;
        int cnt = mergeCount(cur, s, half);
        cnt += mergeCount(cur, half+1, e);
        cnt +=twoCount(cur, s, half, half+1, e);
        return cnt % mod;
    }
    int twoCount(vector<int> cur, int s1, int e1, int s2, int e2){
        int cnt = 0;
        for(size_t i = s1; i <= e1; i++){
            for(size_t j = s2; j <= e2; j++){
                if(cur[i] > cur[j]){
                    cnt++;
                    cnt %= mod;
                }
            }
        }
        return cnt % mod;
    }

    void printv(vector<int> data){
        for(size_t i = 0; i < data.size(); i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int v[8] = {4, 7, 12, 5, 6, 1, 2, 9};
    int ans[8] = {0, 0, 0, 2, 2, 5, 5, 1};
    Solution sl;
    cout << sl.InversePairs(vector<int>(&v[0], (&v[0])+8));
    //sl.printv(vector<int>(&ans[0], (&ans[0])+8));
    return 0;
}
