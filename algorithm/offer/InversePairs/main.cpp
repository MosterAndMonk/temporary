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

    int mergeCount(vector<int>& cur, int s, int e){
        if(s == e){
            return 0;
        }
        int half = s + (e-s)/2;
        long long cnt = mergeCount(cur, s, half);
        cnt += mergeCount(cur, half+1, e);
        cnt += twoCount(cur, s, half, half+1, e);
        return cnt % mod;
    }
    int twoCount(vector<int>& cur, int s1, int e1, int s2, int e2){
        long long cnt = 0;
        vector<int> cur_o((e2-s1)+1);
        for(size_t j = 0; j < (e2-s1)+1; j++){
            cur_o[j] = cur[s1+j];
        }
        int i = e2;
        for(; i >= s1 && e1 >= s1 && e2 >= s2;){
                if(cur_o[e1-s1] > cur_o[e2-s1]){
                    cur[i] = cur_o[e1-s1];
                    i -= 1;
                    e1 -= 1;
                    cnt += ((e2-s2+1)%mod);
                }
                else{
                    cur[i] = cur_o[e2-s1];
                    i -= 1;
                    e2 -= 1;
                }

        }
        while(e1 >= s1){
             cur[i] = cur_o[e1-s1];
             i -= 1;
             e1 -= 1;
        }
        while(e2 >= s2){
            cur[i] = cur_o[e2-s1];
            i -= 1;
            e2 -= 1;
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
