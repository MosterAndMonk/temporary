#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void rev(string& str, int s, int e){
        if(s >= e){
            return;
        }
        for(int i = s; i < s+(e-s+1)/2; i++){
            char c = str[i];
            str[i] = str[e-i+s];
            str[e-i+s] = c;
        }
    }
    string ReverseSentence(string str) {
        int l = str.size();
        rev(str, 0, l-1);

        int s = 0, e = 0;
        while(s < l && e <= l){
            if(str[e] == ' ' || e == l){
                rev(str, s, e-1);
                //cout << str << endl;
                s = e+1;
            }
            e ++;
        }

        return str;
    }

    string ReverseSentence1(string str) {
        vector<string> v;
        splitString(str, v, " ");
        string ans = "";
        for(int i = v.size()-1; i >= 0; i--){
            ans += v[i];

            if(i != 0){
                ans +=" ";
            }
        }
        cout << str.length() << endl << ans.length() << endl;
        return ans;
    }

    void splitString(const string s, vector<string> & v, const string c){
        string::size_type pos1, pos2;
        pos1 = 0;
        pos2 = s.find(c);
        while(pos2 != string::npos){
            v.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2 + c.length();// c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length()){
            v.push_back(s.substr(pos1, s.length()-pos1));
        }
    }
};

int main()
{
    Solution sl;

    //cout << " |" << sl.ReverseSentence("Hello world! la wa") << "| ";
    cout << " |" << sl.ReverseSentence("student. a am I") << "| ";
    //cout << " |" << sl.ReverseSentence("you are a pig") << "| ";
            //cout << str << endl;
       //str = "you are a pig monster";
        //str = "uoy era a retsnom";
    return 0;
}
