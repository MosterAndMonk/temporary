#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
class Solution {
public:
    int calc(int n){
        return (n*(n+1)) /2;
    }
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        for(int i = 0; i < A.size();i++){
            if(A[i] < L){
                A[i] = -1;
            }
            else if(A[i] > R){
                A[i] = 1;
            }
            else{
                A[i] = 0;
            }
         }

        int sum_0 = 0, continue_0 = 0;
        int sum_1 = 0, continue_1 = 0;
        for(int i = 0; i < A.size(); i++){
            //printf("A[%d]=%d\n", i, A[i]);
            if(A[i] != 1){
                continue_0++;
            }
            else{
                sum_0 += calc(continue_0);
                //printf("sum_0=%d continue_0=%d\n", sum_0, continue_0);
                continue_0 = 0;
            }

            if(A[i] == -1){
                continue_1++;
            }
            else{
                sum_1 += calc(continue_1);
                //printf("sum_1=%d continue_1=%d\n", sum_1, continue_1);
                continue_1 = 0;
            }
        }
        sum_0 += calc(continue_0);
        sum_1 += calc(continue_1);
        return sum_0 - sum_1;
    }
};
int main()
{
    int a[4] = {2,1,4,3};
    Solution sl;
    vector<int> A((&a[0]), ((&a[0])+4));
    cout << sl.numSubarrayBoundedMax(A, 2, 3)<<endl;

    return 0;
}
