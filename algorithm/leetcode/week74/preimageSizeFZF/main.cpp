#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
class Solution
{
    int pow5[15];
public:
    Solution()
    {
        pow5[0] = 1;
        for(int i = 1; i < 15; i++)
        {
            pow5[i] = pow5[i-1]*5;
        }
    }
public:

    int preimageSizeFZF(int K)
    {
        int k = bina_find(0, K, K);
        if(k == -1){
            return 0;
        }
        else{
            return 5;
        }
    }

    int calc(int n){
        int sum = 0;
        for(int i = 0; i < 15 && n >= pow5[i]; i++){
            sum += n/pow5[i];
        }
        return sum;
    }

    int bina_find(int s, int e, int target){
        if(s > e){
            return -1;
        }

        int h = s + (e-s)/2, c_h = calc(h);
        if(target == c_h){
            return h;
        }
        else if(target < c_h){
            return bina_find(s, h-1, target);
        }
        else{
            return bina_find(h+1, e, target);
        }
    }
};
    int preimageSizeFZF1(int K)
    {
        if(K == 0)
        {
            return 5;
        }
        int i = 0, sum = 0;
        int M = K;
        while(M > 0)
        {
            M = (int)M/5;
            sum = sum + (int)pow(5, i);
            i++;
        }
        if((K%sum)!= 0)
        {
            if((K - K/sum) % 5 == 0)
            {
                return -1;
            }
            else
            {
                return (K - (int)(K / sum)) * 5;
            }
        }
        return (K - (int)(K % sum)) * 5;
    }

int main()
{
    Solution sl;
    for(int i = 1; i < 200; i++)
    {
        printf("%d %d\n",i, sl.preimageSizeFZF(i));
    }
    cout << "Hello world!" << endl;
    return 0;
}
