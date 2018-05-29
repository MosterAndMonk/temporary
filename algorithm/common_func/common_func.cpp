#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

string to_string(unsigned long long n){
    char buf[30] = {'\0'};
    sprintf(buf, "%llu", n);
    return string(buf);
}
    void printV(vector<pair<int, int> >& v){
        for(size_t i = 0; i < v.size(); i++)
        {
            cout << v[i].first << " " <<v[i].second << endl;
        }
    }

    void printV(vector<string> v)
    {
        for(size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void printV(vector<int> v)
    {
        for(size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    void printV(vector<double> v)
    {
        for(size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
