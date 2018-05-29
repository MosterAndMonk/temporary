#include <iostream>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()){
            return 0;
        }

        int l = str.length();

        bool is_negative = false;
        long sum = 0;

        for(int i = 0; i < l; i++){
            if(i == 0 && (str[i] == '+' || str[i] == '-')){
                if(str[i] == '-'){
                    is_negative = true;
                }
                continue;
            }

            if(str[i] > '9' || str[i] < '0'){
                return 0;
            }

            sum *= 10;
            sum += str[i] -'0';
        }

        if(is_negative){
            sum = -sum;
        }

        return sum;
    }
};

int main()
{
    Solution sl;
    cout << sl.StrToInt("-123455") << endl;
    cout << sl.StrToInt("-12345a") << endl;
    cout << sl.StrToInt("") << endl;
    return 0;
}
