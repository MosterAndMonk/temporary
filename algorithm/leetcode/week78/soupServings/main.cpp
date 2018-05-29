#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

class Solution {
public:
    double soupServings(int N) {
        int n = N/25;
        vector< vector<double> >p_AB(n+1, vector<double> (n+1, -1.0));
        double pr = 0.0;
        for(int i = 0; i < 4; i++){
            pr += dfs(p_AB, N, N, 1);
        }
        return pr*0.25;
    }
    double dfs(vector< vector<double> >& p_AB, int A, int B, int n){
        if(A <= 0 && A < B){
            return 1.0;
        }
        else if(A == B && A <= 0){
            return 0.5;
        }
        else if(B <= 0 && B < A){
            return 0.0;
        }

        int A_25 = A/25, B_25 = B/25;

        if(p_AB[A_25][B_25] > -1.0){
            return p_AB[A_25][B_25];
        }

        double pr = 0.0;
        for(int i = 0; i < 4; i++){
            pr += dfs(p_AB, A-(100-25*i), B-25*i, n+1);
        }
        p_AB[A_25][B_25] = pr*0.25;
        return p_AB[A_25][B_25];
    }

};

int main()
{
    Solution sl;
    //vector<double> v(30, -1);
    double next = 0.0;
    for(int i = 0; i < 1000; i++){
        double cur = sl.soupServings(i*25);
        cout << i*25 << " " << cur << endl;
        next = cur;
    }/*
    for(int i = 101; i < 152; i++){
        if(i % 5 == 0){
            cout << "ok ";
        }
        cout << i << " " << sl.soupServings(i) << endl;
    }*/

    return 0;
}
