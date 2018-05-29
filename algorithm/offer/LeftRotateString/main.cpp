#include <iostream>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {

        int l = str.length();
        if(l <= 0){
            return str;
        }
        n = n % l;

        string ans = str;
        for(int i = 0; i < (l-n); i++){
            ans[i] = str[i+n];
        }
        for(int i = 0; i < n; i++){
            ans[i+(l-n)] = str[i];
        }
        return ans;
    }
};

int main()
{
    string str = "Hello_world!";
    Solution sl;
    cout << sl.LeftRotateString(str, 15) << endl;
    return 0;
}
