#include <iostream>
#include <string.h>

using namespace std;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

void printUsed(bool* isUsed, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << isUsed[i*cols+j] << " ";
        }
        cout << endl;
    }
}

bool isPath(char* matrix, int rows, int cols, char* str, int x, int y, int i, bool* isUsed)
{
    bool res = false;

    if(i >= strlen(str)){
         return res;
    }
    else if(i == strlen(str)-1){
        res = true;
        return res;
    }

    isUsed[x*cols+y] = true;

    for(int j = 0; j < 4; j++){
        int nx = x + dx[j], ny = y + dy[j];
        if(0 <= nx && nx <= rows && 0 <= ny && ny <= cols && !isUsed[nx*cols+ny]){
            int ni = i + 1;
            if(str[ni] == matrix[nx*cols+ny]){
                //cout << matrix[nx*cols+ny] << " " << str[ni] << " " << ni << endl;
                //printUsed(isUsed, rows, cols);
                bool ret = isPath(matrix, rows, cols, str, nx, ny, ni, isUsed);
                res = res || ret;

                isUsed[nx*cols+ny] = false;
            }
        }
    }

    return res;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    bool res = false;
    bool isUsed[rows*cols];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i*cols+j] == str[0]){
                memset(isUsed, 0, sizeof(bool)*rows*cols);
                bool ret = isPath(matrix, rows, cols, str, i, j, 0, isUsed);
                res = res || ret;
            }
        }
    }
    return res;
}

int main()
{
    /*
    char matrix[] = "abcdcdefghjkkdec";
    char str[] = "ghdef";

    cout << hasPath(matrix, 4, 4, str);

    char matrix[] = "abcesfcsadee";
    char str[] = "bcced";

    cout << hasPath(matrix, 3, 4, str);
    */
    /*
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char str[] ="SLHECCEIDEJFGGFIEK";
    cout << hasPath(matrix, 5, 8, str);
    */
    char matrix[] = "A";
    char str[] ="A";
    cout << hasPath(matrix, 1, 1, str);
    return 0;
}

/*
abcd
cdef
ghjk
kdec

ghdef
*/
