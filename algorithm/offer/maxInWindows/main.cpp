#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution1 {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if(size > num.size() || size == 0){
            return vector<int>(0);
        }

        int n_ans = num.size() - size + 1;
        vector<int> ans(n_ans, -1);
        for(int i = 0; i < size; i++){
            //dq.push_back(num[i]);
            ans[0] = max(ans[0], num[i]);
        }
        for(int i = 1; i < n_ans; i++){
            for(int j = 0; j < size; j++){
                ans[i] = max(ans[i], num[i+j]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
       vector<int> ans;
       if(size == 0 || size > num.size() || num.size() == 0){
           return ans;
       }
       deque<int> dq;
       dq.push_back(0);
       for(int i = 1; i < size; i++){
           while(!dq.empty() && num[i] > num[dq.back()]){
               dq.pop_back();
           }
           dq.push_back(i);
       }
       ans.push_back(num[dq.front()]);
       for(int i = size; i < num.size(); i++){
           while(!dq.empty() && (num[i] > num[dq.back()])){
               dq.pop_back();
           }
           if(!dq.empty() && i-size >= dq.front()){
               dq.pop_front();
           }
           dq.push_back(i);
           ans.push_back(num[dq.front()]);
       }
       return ans;
    }
};
int main()
{
    int v[8] = {2, 3, 4, 2, 6, 2, 5, 1};
    Solution sl;
    vector<int> ans = sl.maxInWindows(vector<int> (&v[0], (&v[0])+8), 3);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
