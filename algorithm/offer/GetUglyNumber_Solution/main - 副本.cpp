#include <iostream>

using namespace std;
class Solution {
public:
    bool isUglyNumber(int n){
        while(n % 2 == 0){
            n /= 2;
        }
        while(n % 3 == 0){
            n /= 3;
        }
        while(n % 5 == 0){
            n /= 5;
        }
        return n == 1;
    }
    int GetUglyNumber_Solution(int index) {
        int uglyNumber = 1;
        for(int i = 1, n = 1; i <= index; n++){
            if(isUglyNumber(n)){
                uglyNumber = n;
                i++;
            }
        }
        return uglyNumber;
    }
};

int main()
{
    Solution sl;
    while(1){
        int n;
        cin >> n;
        cout << sl.GetUglyNumber_Solution(n) << endl;
    }

    cout << "Hello world!" << endl;
    return 0;
}
