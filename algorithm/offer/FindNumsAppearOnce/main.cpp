#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int o_r = 0;
        int n = data.size();
        for(int i = 0; i < n; i++){
            o_r = data[i] ^ o_r;
        }

        int index_r_1 = 0;
        while( ((o_r & 1) != 1) && (index_r_1 < 8 * sizeof(int)) ){
            o_r  = o_r >> 1;
            index_r_1 ++;
        }

        *num1 = 0;
        *num2 = 0;
        for(int i = 0; i < n; i++){
            int a_d = data[i] >>(index_r_1);
            if(a_d & 1){
                *num2 ^= data[i];
            }
            else{
                *num1 ^= data[i];
            }
        }

    }
};

int main()
{
    Solution sl;
    //int d[8] = {3, 4, 7, 2, 3, 4, 7, 5};
    int d[8] = {2, 4, 3, 6, 3, 2, 5, 5};
    int num1, num2;
    sl.FindNumsAppearOnce(vector<int> ((&d[0]), (&d[0])+8), &num1, &num2);
    cout << num1 << " " << num2 << endl;

    return 0;
}
