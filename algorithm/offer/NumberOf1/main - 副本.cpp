#include <iostream>
#include <bitset>

using namespace std;
int NumberOf1(int n)
{
    n = (n&0x55555555)+((n>>1)&0x55555555);
    bitset<32> bn(n);
    cout << bn << endl;
    n = (n&0x33333333)+((n>>2)&0x33333333);
    bitset<32> bn1(n);
    cout << bn1 << endl;
    n = (n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
    bitset<32> bn2(n);
    cout << bn2 << endl;
    n = (n&0x00ff00ff)+((n>>8)&0x00ff00ff);
    bitset<32> bn3(n);
    cout << bn3 << endl;
    n = (n&0x0000ffff)+((n>>16)&0x0000ffff);
    bitset<32> bn4(n);
    cout << bn4 << endl;
    return n;
}
int  NumberOf11(int n)
{
    int cur = n, cnt = 0;
    for(int i = 1; i < 32; i++)
    {
        if (cur&1)
        {
            cnt ++;
        }
        cur = cur >> 1;
    }
    return cnt;
}
int main()
{
    while(1)
    {
        int n;
        cin >> n;
        bitset<32> bn(n);
        cout << bn << endl << NumberOf1(n) << endl << endl;
    }
    return 0;
}//-2147483648
