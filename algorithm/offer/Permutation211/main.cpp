#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string &A, string &B) {
        // write your code here
        int na = A.size(), nb = B.size();
        if(na == nb){
            sort(A.c_str(), A.c_str()+na);
            sort(B.c_str(), B.c_str()+nb);
            return A == B;
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
