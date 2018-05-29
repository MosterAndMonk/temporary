#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution {
    int n;
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    int sign[200][200];
public:
    int movingCount(int threshold, int rows, int cols)
    {
        n = 0;

        if(threshold >= 0 && rows >= 0 && cols >=0){
            memset(sign, 0, 200*200*sizeof(int));
            dfs(threshold, rows, cols, 0, 0);
        }

        return n;
    }

    int sum_d(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n/=10;
        }
        return sum;
    }

    void dfs(int thre, int r, int c, int x, int y){
        n++;
        sign[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r){
                continue;
            }
            if(sign[nx][ny] ){
                continue;
            }
            if( (sum_d(nx)+sum_d(ny)) > thre){
                continue;
            }
            /*
            cout << nx << " x_y " << ny << endl;
            cout << sum_d(nx) << " sum " << sum_d(ny) << endl;
            */
            dfs(thre, r, c, nx, ny);
        }
    }

    void print_sign(int r, int c){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << sign[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution sl;
    //cout << sl.movingCount(2, 3, 4) << endl;
    cout << sl.movingCount(18, 36, 39) << endl;
    //sl.print_sign(36, 39);
    return 0;
}
