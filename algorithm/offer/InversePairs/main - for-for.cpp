#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int> data_copy = data;

        int n = data.size();
        int sum = (n*(n-1))/2;

        map<int, int> m;
        for(int i = 0; i < n; i++){
            m[data[i]] = i;
        }
        map<int, int> m_cnt = m;

        sort(data.begin(), data.end());

        for(int i = 0, l = n; i < n; i++, l--){
            int cur = data[i];
            //cout << i << " " << (l-m_cnt[cur]-1) << endl;
            sum = sum - (l-m_cnt[cur]-1);
            for(int j = m[cur]+1; j < n; j++){
                m_cnt[data_copy[j]] -= 1;
            }

        }

        return sum;
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
