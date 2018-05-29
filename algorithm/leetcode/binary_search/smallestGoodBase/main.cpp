#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

string to_string(unsigned long long n){
    char buf[30] = {'\0'};
    sprintf(buf, "%llu", n);
    return string(buf);
}

class Solution {
    typedef unsigned long long ull;
public:
    string smallestGoodBase(string n) {
        ull nn = atoll(n.c_str());
        int pn = log(nn)/log(2)+1;
        for(int a = pn; a >= 2; a--){
            ull p_k = 1, sum = 1, k = pow(nn, 1.0/(a-1));
            for(int i = 1; i < a; i++){
                p_k *= k;
                sum += p_k;
            }
            if(sum == nn){
                return to_string(k);
            }

        }
        return to_string(nn-1);
    }
};

int main()
{
    Solution sl;
    //cout << sl.smallestGoodBase("13");
    cout << sl.smallestGoodBase("15");
    //cout << sl.smallestGoodBase("4681");
    //cout << sl.smallestGoodBase("1000000000000000000");
    return 0;
}
