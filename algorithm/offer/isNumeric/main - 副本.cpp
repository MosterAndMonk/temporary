#include <iostream>

using namespace std;
class Solution {
public:
    bool isNumeric(char* str)
    {
        if(str == NULL){
            return false;
        }
        //cout << str << endl;
        int e_n = 0, d_n = 0;
        int e_pos = 100, d_pos = -1;
        for(int i = 0; str[i] != '\0'; i++){
            //cout << str[i] << " ";
            //cout << is_legal(str[i]) << endl;
            if(!is_legal(str[i])){
                return false;
            }
            else{
                if( is_plus_minus(str[i]) ){
                    if( i==0 || ( (i > 1) && (is_e(str[i-1])) ) ){
                        if( str[i+1] != '\0' && !is_e(str[i+1]) ){

                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
                else if(is_e(str[i])){
                    if(i-1 >= 0 && str[i+1] != '\0'){
                        e_pos = i;
                        e_n ++;
                    }
                    else{
                        return false;
                    }
                }
                else if(str[i] == '.'){
                    if(str[i+1] != '\0'){
                        d_pos = i;
                        d_n ++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(e_n < 2 && d_n < 2){
            if(e_pos > d_pos){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    bool is_legal(char a){
        if('0' <= a  && a <= '9'){
            return true;
        }
        else if(is_e(a)||
                is_plus_minus(a)||
                a == '.'){
            return true;
        }
        else {
            return false;
        }
    }
    bool is_plus_minus(char a){
        return (a == '+' || a == '-');
    }
    bool is_e(char a){
        return (a == 'e'|| a == 'E');
    }

};
int main()
{
    Solution sl;

    cout << endl << sl.isNumeric("Hello world!") << " 0" << endl;
    cout << sl.isNumeric("+100") << " 1" << endl;
    cout << sl.isNumeric("5e2") << " 1" << endl;
    cout << sl.isNumeric("-123") << " 1" << endl;
    cout << sl.isNumeric("3.1415926") << " 1" << endl;
    cout << sl.isNumeric("-1E-16") << " 1" << endl;
    cout << sl.isNumeric("12e") << " 0" << endl;
    cout << sl.isNumeric("-1a3.14") << " 0" << endl;

    cout << sl.isNumeric("1.2.3") << " 0" << endl;
    cout << sl.isNumeric("+-5") << " 0" << endl;
    cout << sl.isNumeric("12e+4.3") << " 0" << endl;
    cout << sl.isNumeric("123.45e+6") << " 1" << endl;


    return 0;
}
