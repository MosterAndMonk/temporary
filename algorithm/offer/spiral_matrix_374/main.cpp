#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

void printV(const vector<int>& v)
{
    for(size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

class Solution1 {
public:
    /**
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    vector<int> spiralOrder(vector<vector<int> > matrix) {
        const int INF = -(1 << 30);
        int dy[4] = {1, 0, -1, 0};
        int dx[4] = {0, 1, 0, -1};
        // write your code here
        vector<int> ans;
        int m = matrix.size();
        if(m > 0){
            int n = matrix[0].size();

            vector<bool> tmp(n, false);
            vector< vector<bool> > sign_ma(m, tmp);

            size_t num_ans = m*n;
            int cur_x = 0, cur_y = 0, cur_d = 0;

            ans.push_back(matrix[cur_x][cur_y]);
            sign_ma[cur_x][cur_y] = true;

            while(ans.size() < num_ans){
                int x = cur_x + dx[cur_d];
                int y = cur_y + dy[cur_d];

                if(0 > x || x >= n ||
                    0 > y || y >= m ||
                    sign_ma[x][y]){

                    cur_d = (cur_d + 1)%4;
                }
                else{
                    ans.push_back(matrix[x][y]);
                    sign_ma[x][y] = true;
                    cur_x = x;
                    cur_y = y;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        const int INF = -(1 << 30);
        int dy[4] = {1, 0, -1, 0};
        int dx[4] = {0, 1, 0, -1};
        // write your code here
        vector<int> ans;
        int m = matrix.size();
        if(m > 0){
            int n = matrix[0].size();
            size_t num_ans = m*n;
            int cur_x = 0, cur_y = 0, cur_d = 0;

            ans.push_back(matrix[cur_x][cur_y]);
            matrix[cur_x][cur_y] = INF;

            while(ans.size() < num_ans){
                int x = cur_x + dx[cur_d];
                int y = cur_y + dy[cur_d];
                //printf ("%d %d\n", x, y);
                if(0 > x || x >= m ||
                    0 > y || y >= n ||
                    matrix[x][y] == INF){

                    cur_d = (cur_d + 1)%4;
                }
                else{

                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = INF;
                    cur_x = x;
                    cur_y = y;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    const int INF = -(1 << 30);
    cout << INF << endl;
    vector< vector< int > > v;
    int n = 5;
    for(int i = 0; i < n; i++ ){
        vector<int> v2;
        for(int j = 1; j <= n-1; j++){
            int vvv = i*n+j;
            cout << vvv << " " ;
            v2.push_back(vvv);
        }
        v.push_back(v2);
        cout << endl;
    }

    printV( sl.spiralOrder(v) );
    return 0;
}
