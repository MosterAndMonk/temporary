#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

void printV(vector<pair<int, int> >& v){
    for(size_t i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " <<v[i].second << endl;
    }
}

class Solution {
    int max_pa;
public:
    static bool compare(pair<int, int>& A, pair<int, int>& B){
        if(A.first == B.first){
            return A.second > B.second;
        }
        else{
            return A.first > B.first;
        }
    }

    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), compare);
        printV(envelopes);
        vector<int> dp(n, 1);

        int max_ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < i; j++){
                if(compare(envelopes[j], envelopes[i])){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            max_ans = max(dp[i], max_ans);
        }
        return max_ans;
    }

/****************************************************************************/
    int maxEnvelopes1(vector<pair<int, int> >& envelopes) {
        int n = envelopes.size();
        vector< vector<int> > g(n, vector<int> (n, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
                        g[i][j] = 1;
                    }
                    else{
                        g[i][j] = 0;
                    }
                }
            }
        }

        max_pa = 0;
        for(int i = 0; i < n; i++){
            dfs(g, envelopes, i, 0);
        }

        return max_pa+1;
    }

    void dfs(const vector< vector<int> >& g, const vector<pair<int, int> >& enve, int cur, int pa){
        if(pa >= enve.size()-1){
            max_pa = max(pa, max_pa);
            return;
        }

        for(int i = 0; i < enve.size(); i++){
            if(i != cur){
                if(g[cur][i]==1){
                    dfs(g, enve, i, pa+1);
                }
            }
        }

    }
};

int main()
{
    Solution sl;
    vector<pair<int, int> > enve;
    enve.emplace_back(5, 4);
    enve.emplace_back(6, 4);
    enve.emplace_back(6, 7);
    enve.emplace_back(2, 3);
    cout << sl.maxEnvelopes(enve);

    return 0;
}
//[[20,48],[12,35],[32,16],[30,17],[35,23],[37,33],[14,10],[23,31],[8,7],[17,6],[6,19],[3,6],[22,34],[10,26],[16,46],[20,11],[20,28],[39,33],[44,47],[29,18],[8,25],[17,24],[43,27],[45,12],[40,29],[37,10],[49,20],[2,4],[33,1],[46,27],[39,24],[34,6],[15,15],[21,40],[7,30],[19,9],[11,39],[29,31],[28,37],[4,37],[8,36],[38,1],[48,46],[4,1],[43,29],[41,32],[19,23],[37,35],[31,9],[8,1],[34,30],[2,20],[49,21],[16,26],[38,12],[27,20],[43,7],[25,8],[17,36],[42,40],[45,14],[16,10],[19,47],[5,37],[21,7],[30,3],[42,40],[18,40],[35,41],[12,33],[4,15],[40,22],[4,29],[27,27],[41,40],[12,33],[37,41],[21,11],[5,24],[4,32]]
