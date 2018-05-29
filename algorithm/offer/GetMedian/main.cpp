#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution1 {
    vector<int> v;
public:
    void Insert(int num)
    {
        v.push_back(num);
    }

    double GetMedian()
    {
        int n = v.size();
        sort(&(v[0]), &(v[0])+n);
        double median;
        if(n&1){
            median = v[n/2];
        }
        else{
            median = (v[n/2-1] + v[n/2])*0.5;
        }
        return median;
    }

};

class Solution {
    int cnt;
    priority_queue<int, vector<int>, less<int> >  max_h;
    priority_queue<int, vector<int>, greater<int> > min_h;
public:
    Solution(){
        cnt = 0;
    }
    void Insert(int num)
    {
        cnt ++;
        if(!min_h.empty() && num > min_h.top()){
            min_h.push(num);
        }
        else{
            max_h.push(num);
        }

        if(max_h.size() == min_h.size() + 2){
            min_h.push(max_h.top() );
            max_h.pop();
        }
        if(min_h.size() == max_h.size()+1){
            max_h.push(min_h.top());
            min_h.pop();
        }
    }

    double GetMedian()
    {
        if(cnt%2){
            return max_h.top();
        }
        else{
            return (max_h.top() + min_h.top() )*0.5;
        }

    }

};

int main()
{
    int a[] = {5, 2, 3, 4, 1, 6, 7, 0, 8};
    Solution sl;
    for(int i = 0; i < 9; i++){
        sl.Insert(a[i]);
        cout << sl.GetMedian() << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
