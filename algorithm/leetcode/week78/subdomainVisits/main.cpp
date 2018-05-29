#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

void printV(vector<string> v)
{
    for(size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> sum_map;

        for(int i = 0; i < cpdomains.size(); i++){
            vector<string> v_n(0);
            splitString(cpdomains[i], v_n, " ");
            printV(v_n);
            int nn = atoi(v_n[0].c_str());

            madd(sum_map, v_n[1], nn);

            vector<string> domain(0);
            splitString(v_n[1], domain, ".");
            if(domain.size() == 2){
                madd(sum_map, domain[1], nn);
            }
            else if(domain.size() == 3){
                madd(sum_map, domain[2], nn);
                string ss = domain[1]+"."+domain[2];
                madd(sum_map, ss, nn);
            }
        }

        vector<string> ans;
        for(map<string, int>::iterator it; it != sum_map.end(); it++){
            char buf[50] = {0};
            cout << it->second;
            sprintf(buf, "%d", it->second);
            string ans_li = string(buf) + " " + it->first;
            ans.push_back(ans_li);
        }

        return ans;
    }

    void madd(map<string, int>& sum_map, string n, int v){
        map<string,int>::iterator it = sum_map.find(n);

        if(it == sum_map.end()){
            sum_map[n] = v;
        }
        else{
            sum_map[n] += v;
        }
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
    vector<string> v;
    v.push_back("9001 discuss.leetcode.com");
    vector<string> v2 = sl.subdomainVisits(v);
    printV(v2);
    return 0;
}
