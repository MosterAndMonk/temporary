#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {

        int l = numbers.size();
        if(l <= 0){
            return false;
        }

        sort(numbers.begin(), numbers.end());
        int cnt_0 = 0, pos_s = -1;

        for(int i = 0; i < l; i++){
            if(numbers[i] != 0){
                pos_s = i;
                break;
            }
            else{
                cnt_0 ++;
            }
        }

        if(pos_s != -1){

            bool is_n_same = false;
            for(int i = pos_s; i < l; i++){
                if(numbers[i-1] == numbers[i]){
                    is_n_same = true;
                }
            }
            if(is_n_same){
                return false;
            }
            int pre_n = numbers[l-1] - numbers[pos_s] + 1;
            int act_n = l - pos_s;
            if( (pre_n - act_n) <= cnt_0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }

    void printV( vector<int> v){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    //int d[7] = {0, 1, 2, 4, 5, 6, 7};
    //int d[7] = {2, 3, 5, 6, 9, 10, 1};
    int d[7] = {2, 0, 0, 0, 2, 0, 0};
    Solution sl;
    cout << sl.IsContinuous(vector<int> ((&d[0]), (&d[0]) + 7) );
    //cout << "Hello world!" << endl;
    return 0;
}
