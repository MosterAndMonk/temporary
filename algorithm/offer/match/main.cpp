#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool is_single_match(char a, char b){
        if(a == '.' || b == '.'){
            return true;
        }
        else{
            return (a == b);
        }
    }

    bool match(char* str, char* pattern)
    {
        if(str == NULL || pattern == NULL){
            return false;
        }
        //printf("str: %s pattern: %s\n", str, pattern);
        int ls = strlen(str);
        int lp = strlen(pattern);
        if(ls == 0 && lp == 0){
            return true;
        }

        int ss = 0, sp = 0;
        while(ss < ls && sp+1 < lp && pattern[sp+1] != '*'){
            if(is_single_match(str[ss], pattern[sp])){
                ss++;
                sp++;
            }
            else{
                break;
            }
        }
        //printf("ss: %d sp: %d\n", ss, sp);
        int is = ls-1, ip = lp-1;
        while(is >= ss || ip >= sp){
            if(pattern[ip] == '*'){
                ip--;
                //printf("str[%d]: %c pattern[%d]: %c \n", is, str[is], ip, patt    4 eern[ip]);
                while(is >= ss && is_single_match(str[is], pattern[ip])){
                    is--;
                }
                if(ip >= sp){
                    ip--;
                }
            }
            else if(is_single_match(pattern[ip], str[is])){
                is--;
                ip--;
            }
            else{
                return false;
            }
        }
        //printf("is: %d ip: %d\n", is, ip);

        if(is == ip){
            return true;
        }
        else{
            return false;
        }

    }
};

int main()
{
    Solution sl;

    cout << sl.match("aaa", "a.a") << " 1" << endl;
    cout << sl.match("aaa", "ab*ac*a") << " 1" <<endl;
    cout << sl.match("aa.a", "ab*a") << " 0" << endl;
    cout << sl.match("", "") << " 1" << endl;
    cout << sl.match("", ".*") << " 1" << endl;

    cout << sl.match("a", ".*") << " 1" << endl;

    cout << sl.match("aab", "c*a*b") << " 1" << endl;

    cout << sl.match("", ".") << " 0" << endl;
    cout << sl.match("a.", "a") << " 0" << endl;

    cout << sl.match("a", "ab*") << " 1" << endl;

    cout << sl.match("aaa", "aa*") << " 1" << endl;
    cout << sl.match("aaa", "ab*a*c*a") << " 1" << endl;
    cout << sl.match("baaa", "bab*a*c*a") << " 1" << endl;
    return 0;
}
