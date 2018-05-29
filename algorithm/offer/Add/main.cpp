#include <iostream>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        bool s[32] = {0};
        bool c = 0;
        int sum = 0;
        for(int i = 0; i < 32; i++){
            bool a = (num1 >> i)&1;
            bool b = (num2 >> i)&1;
            s[i] = a^b^c;
            c = (a&c)|(b&c)|(a&b);
            sum |= (unsigned int)(s[i])<<i;
        }
        return sum;
    }
};

int main()
{
    Solution sl;
    cout << sl.Add(7, 3);

    return 0;
}
