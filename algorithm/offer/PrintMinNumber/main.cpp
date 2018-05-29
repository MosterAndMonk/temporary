#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        //sort(numbers.begin(), numbers.end(), compare);
        mySort(numbers);
        char minN[200];
        int j = 0;
        for(size_t i = 0; i < numbers.size(); i++)
        {
            j += sprintf(minN + j, "%d", numbers[i]);
        }
        minN[j] = '\0';
        return string(minN);
    }
    int stack2n(stack<int> s)
    {
        int n = 0;
        while(!s.empty())
        {
            n *= 10;
            n += s.top();
            s.pop();
        }
        return n;
    }

    void n2stack(int n, stack<int>& s)
    {
        if(s.empty() != true)
        {
            return;
        }
        while(n > 0)
        {
            s.push(n % 10);
            n /= 10;
        }
    }

    bool compare(int a, int b){
        char ab[200];
        char ba[200];
        int j = sprintf(ab, "%d%d", a, b);
        ab[j] = '\0';
        j = sprintf(ba, "%d%d", b, a);
        ba[j] = '\0';
        int rc = strcmp(ab, ba);
        return rc < 0;
    }

    bool compare1(int a, int b)
    {
        if(a == b)
        {
            return false;
        }
        stack<int> sa, sb;
        n2stack(a, sa);
        n2stack(b, sb);
        while(!(sa.empty() && sb.empty()))
        {
            if(sa.empty())
            {
                int bb = stack2n(sb);
                return compare(a, bb);
            }
            else if(sb.empty())
            {
                int aa = stack2n(sa);
                return compare(aa, b);
            }
            else if(sa.top() == sb.top())
            {
                sa.pop();
                sb.pop();
            }
            else
            {
                return sa.top() < sb.top();
            }
        }
        return false;
    }

    void printV(vector<int> v)
    {
        for(size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void mySort(vector<int>& numbers)
    {
        for(size_t i = 0; i < numbers.size(); i++)
        {
            //printV(numbers);
            int minV = numbers[i+1], minIndex = i+1;
            for(size_t j = minIndex; j < numbers.size(); j++)
            {
                if(compare(numbers[j], minV))
                {
                    minV = numbers[j];
                    minIndex = j;
                }
            }
            if(minIndex < numbers.size() && compare(minV, numbers[i]))
            {
                numbers[minIndex] = numbers[i];
                numbers[i] = minV;
            }
        }
    }

};

int main()
{
    Solution sl;
    int vv[3] = {3, 321, 332};
    //int vv[] = {};
    //int vv[5] = {3,5,1,4,2};
    vector<int> v(&vv[0], (&vv[0])+3);
    //cout << sl.compare(vv[0], vv[1]) << endl;
    cout << sl.PrintMinNumber(v) << endl;
    //mySort(v);
    //printV(v);

    return 0;
}
