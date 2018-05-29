#include <iostream>
#include <cstdio>

using namespace std;
/********** Sum_Solution1 *****************/
class Temp{
public:
    Temp(){
        sum += n;
        n ++;
    }
    static void set_0(){
        sum = 0;
        n = 1;
    }
    static int sum, n;
};

int Temp::sum = 0;
int Temp::n = 1;
/******************************************/

/********** Sum_Solution2 *****************/
class A;
A* Array[2];
class A{
public:
    virtual int sum(int n){
        return 0;
    }
};

class B: public A{
    int sum(int n){
        return Array[!!n]->sum(n-1)+n;
    }
};
/******************************************/

/********** Sum_Solution3 *****************/
int (*p[2])(int n);
int end1(int n){
    return 0;
}
int sum2(int n){
    return p[!!n](n-1)+n;
}

/******************************************/

/********** Sum_Solution4 *****************/
/******************************************/
class Solution {
public:
    int Sum_Solution1(int n) {
        Temp::set_0();
        Temp* t = new Temp[n];
        int ans = Temp::sum;
        delete [] t;
        t = NULL;
        return ans;
    }
    int Sum_Solution2(int n) {
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;
        return Array[1]->sum(n);
    }

    int Sum_Solution(int n) {
        p[0] = end1;
        p[1] = sum2;
        return p[1](n);
    }

    int Sum_Solution4(int n) {
        return 0;
    }
};

int main()
{
    Solution sl;
    int n = 5;
    while(1){
        printf("%d %d\n", sl.Sum_Solution(n), n*(n+1)>>1);
        cin >> n;
    }
    return 0;
}
