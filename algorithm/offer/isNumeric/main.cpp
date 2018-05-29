#include <iostream>
#include <cstring>
#include <stdio.h>
#include <regex>
#include <string>

using namespace std;
class Solution {
private:
    enum STATUS{END = 0, START, SIGNED1, POINT, INTEGER, FLOAT, EXPONENT, SCIENCE, SIGNED2};
    STATUS dfa[256][9];
public:
    /*************************** {isNumeric3} ************************************/
    bool isNumeric(char* str){
        //cout << str << endl;
        regex reg("^(([\\+-]?[0-9]+)|([\\+-]?[0-9]*(\\.)[0-9]+)|([\\+-]?[0-9]+[eE][\\+-]?[0-9]+)|([\\+-]?[0-9]*(\\.)[0-9]+[eE][\\+-]?[0-9]+))$");
        smatch res;
        //rege
        return (bool)(regex_match(string(str), res, reg));
    }
    /*************************** {isNumeric2} ************************************/
    Solution(){
        for(int i = 0; i < 256; i++){
            for(int j = 0; j < 9; j++){
                dfa[i][j] = END;
            }
        }
        initDFA();
    }
    void initDFA(){
        //1.START
        dfa['+'][START] = SIGNED1;
        dfa['-'][START] = SIGNED1;
        dfa['.'][START] = POINT;
        for(int8_t i = '0'; i <= '9'; i++){
            dfa[i][START] = INTEGER;
        }

        //2.SIGNED1
        dfa['.'][SIGNED1] = POINT;
        for(int8_t i = '0'; i <= '9'; i++){
            dfa[i][SIGNED1] = INTEGER;
        }

        //3.INTEGER
        dfa['.'][INTEGER] = POINT;
        dfa['e'][INTEGER] = EXPONENT;
        dfa['E'][INTEGER] = EXPONENT;
        for(int8_t i = '0'; i <= '9'; i++){
            dfa[i][INTEGER] = INTEGER;
        }

        //4.POINT
        for(int8_t i = '0'; i <= '9'; i++){
            dfa[i][POINT] = FLOAT;
        }

        //5.FLOAT
        dfa['e'][FLOAT] = EXPONENT;
        dfa['E'][FLOAT] = EXPONENT;
        for(int8_t i = '0'; i <= '9'; i++){
            dfa[i][FLOAT] = FLOAT;
        }

        //6.EXPONENT
        dfa['+'][EXPONENT] = SIGNED2;
        dfa['-'][EXPONENT] = SIGNED2;
        for(int8_t i = '0'; i <= '9'; i++){
            dfa[i][EXPONENT] = SCIENCE;
        }

        //7.SIGNED2
        for(int8_t i = '0'; i <= '9'; i++){
            dfa[i][SIGNED2] = SCIENCE;
        }

        //8.SCIENCE
        for(int8_t i = '0'; i <= '9'; i++){
            dfa[i][SCIENCE] = SCIENCE;
        }
    }
    STATUS getDFA(int8_t s, int8_t e){
        return dfa[e][s];
    }

    bool isNumeric2(char* str){
        //printDFA();
        int i = 0;
        int l = strlen(str);
        STATUS cur = START;
        //printf("\n%s\n%s", str, printStatus(START));
        while(str[i] && i < l){
            cur = getDFA(cur, str[i]);
            //printf("->%s", printStatus(cur));
            i++;
        }
        //cout << " ";
        if(cur == INTEGER || cur == FLOAT || cur == SCIENCE){
            return true;
        }
        else{
            return false;
        }
    }

    char* printStatus(STATUS s){
        char* str;
        switch (s)
        {
        case END:
            str = "END";
            break;
        case START:
            str = "START";
            break;
        case SIGNED1:
            str = "SIGNED1";
            break;
        case POINT:
            str = "POINT";
            break;
        case INTEGER:
            str = "INTEGER";
            break;
        case FLOAT:
            str = "FLOAT";
            break;
        case EXPONENT:
            str = "EXPONENT";
            break;
        case SCIENCE:
            str = "SCIENCE";
            break;
        case SIGNED2:
            str = "SIGNED2";
            break;
        default:
            str = " ";
            break;
        }
        return str;
    }
    void printDFA(void){

        for(int j = 0; j < 9; j++){
            for(int i = 0; i < 256; i++){
                cout << dfa[i][j] << " ";
            }
            cout << endl;
        }
    }
    /*************************** {isNumeric1} ************************************/
    bool isNumeric1(char* str){
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

    cout << sl.isNumeric("Hello world!") << " 0" << endl;
    cout << sl.isNumeric("+100") << " 1" << endl;
    cout << sl.isNumeric("+5e2") << " 1" << endl;
    cout << sl.isNumeric("-123") << " 1" << endl;
    cout << sl.isNumeric("+3.1415926") << " 1" << endl;
    cout << sl.isNumeric("-1E-16") << " 1" << endl;
    cout << sl.isNumeric("12e") << " 0" << endl;
    cout << sl.isNumeric("-1a3.14") << " 0" << endl;

    cout << sl.isNumeric("1.2.3") << " 0" << endl;
    cout << sl.isNumeric("+-5") << " 0" << endl;
    cout << sl.isNumeric("12e+4.3") << " 0" << endl;
    cout << sl.isNumeric("123.45e+6") << " 1" << endl;

    cout << sl.isNumeric("1.") << endl;


    return 0;
}
