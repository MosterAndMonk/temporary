#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int s = 0, e = nums.size()-1;
        while(s < e){
            int sum = nums[s] + nums[e];
            if(sum = target){
                ans.push_back(s);
                ans.push_back(e);
            }
            else if(sum > target){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
