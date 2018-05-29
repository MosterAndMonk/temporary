#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

class Solution {
    const int max_num = 20001;
public:
    bool is_same_front(const vector<int>& fronts, int ind, int ta){
        bool is_same = false;
        for(int i = 0; i < fronts.size(); i ++){
            if(i != ind){
                is_same |= (fronts[i] == ta);
            }
        }
        return is_same;
    }

    void mySwap(int& a, int& b){
        int tmp1 = a;
        a = b;
        b = tmp1;
    }
    int good_num(vector<int>& fronts, vector<int>& backs){
        int min_flip = max_num;
        for(int i = 0; i < fronts.size(); i++){
            if(fronts[i] != backs[i] && !is_same_front(fronts, i, backs[i])){
                min_flip = min(min_flip,  backs[i]);
            }
        }
        return min_flip;
    }

    int dfs(vector<int>& fronts, vector<int>& backs, int id){
        int n = fronts.size();
        if(id > n-1){
            return max_num;
        }
        int min_flip = max_num;
        for(int i = id; i < n; i++){
            int m1 = dfs(fronts, backs, id+1);
            min_flip = min(good_num(fronts, backs), min(m1, min_flip));

            int m2 = max_num;
            if(fronts[i] != backs[i]){
                mySwap(fronts[i], backs[i]);
                m2 = dfs(fronts, backs, id+1);
            }
            min_flip = min(good_num(fronts, backs), min(min_flip, m2));
        }
        return min_flip;
    }

    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans = max_num;
        ans = dfs(fronts, backs, 0);
        if(ans == max_num){
            ans = 0;
        }
        return ans;
    }
};

int main()
{
    vector<int> v1(2, 1);
    vector<int> v2(2, 2);
    v2[1] = 1;
    /*
    vector<int> v1(2, 1);
    vector<int> v2(2, 2);
    v2[0] = 1;

    vector<int> v1(1, 1);
    vector<int> v2(1, 2);
    */
    Solution sl;
    cout << sl.flipgame(v1, v2) << endl;
    return 0;
}
