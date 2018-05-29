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
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // write your code here
        char * p_s = new char[length+1];
        memcpy(p_s, string, length+1);

        int cnt = 0;
        for(int i = 0; i < length; i++){
            /*
            while(i+1 < length && string[i] == ' ' && string[i+1] == ' '){
                i++;
            }
            */
            printf("s[%d]=%c cnt=%d\n", i, string[i], cnt);
            if(string[i] == ' '){
                string[cnt++] = '%';
                string[cnt++] = '2';
                string[cnt] = '0';
            }
            else{
                string[cnt] = p_s[i];
            }
            cnt++;
        }

        string[cnt] = '\0';
        delete p_s;
        p_s = NULL;

        return cnt;
    }
};

int main()
{
    Solution sl;
    char* s = new char[100];
    memset(s, 0, 100);
    //memcpy(s, "hello world", 11);
    //sl.replaceBlank(s, 11);
    memcpy(s, "hello  world", 12);
    sl.replaceBlank(s, 12);
    cout << s << endl;

    return 0;
}
