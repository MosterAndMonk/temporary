#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int l = A.size();

        vector<int> B(l);
        if(l <= 0){
            return B;
        }

        B[0] = A[0];

        for(int i = 1; i < l-1; i++){
            B[i] = B[i-1] * A[i];
        }

        B[l-1] = B[l-2];

        int temp = 1;
        for(int i = l-2; i > 0; i--){
            temp *= A[i+1];
            B[i] = B[i-1] * temp;
        }

        B[0] = temp * A[1];

        return B;
    }

    void printV(vector<int> v, string s = ""){
        cout << s << " ";
        int n = v.size();
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }

    vector<int> multiply1(const vector<int>& A) {
        int l = A.size();

        vector<int> B(l);
        if(l <= 0){
            return B;
        }

        vector<int> B_c(l);
        B_c[0] = A[0];

        for(int i = 1; i < l; i++){
            B_c[i] = B_c[i-1] * A[i];
        }

        vector<int> A_c(l);

        A_c[l-1] = A[l-1];

        for(int i = l-2; i >= 0; i--){
            A_c[i] = A_c[i+1] * A[i];
        }
        //printV(B, "B");
        //printV(A_c, "A_c");
        B[l-1] = B_c[l-2];

        for(int i = 1; i < l-1; i++){
            B[i] = B_c[i-1] * A_c[i+1];
        }

        B[0] = A_c[1];

        return B;
    }
};

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    Solution sl;
    vector<int> B = sl.multiply(vector<int>((&A[0]), (&A[0])+5));
    for(int i = 0; i < 5; i ++){
        cout << A[i] << " " << B[i] << endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
