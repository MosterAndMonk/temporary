#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > FindContinuousSequence(int sum)
    {
        vector<vector<int> > ans;
        for(int n = sum*2/3; n >= 2; n--)
        {
            int nn_1 = n * (n - 1);
            int sum_2 = sum * 2;
            if((sum_2-nn_1)%(2*n) == 0)
            {
                int a0 = (sum_2-nn_1)/(2*n);
                if(a0 > 0)
                {
                    vector<int> cur_v;
                    for(int i = 0; i < n; i++)
                    {
                        int ai = i + a0;
                        cout << ai << " ";
                        cur_v.push_back(ai);
                    }
                    ans.push_back(cur_v);
                    cout << endl;
                }

            }
        }
        return ans;
    }
};

int main()
{
    while(1){
        int sum = 520;
        cin >> sum;
        Solution sl;
        sl.FindContinuousSequence(sum);
    }

    return 0;
}
