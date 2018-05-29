#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int> > array1)
{
    int h = array1.size(), w = array1[0].size();
    int i = 0, j = w - 1;
    while(i < h && j >= 0)
    {
        if (array1[i][j] == target)
                return true;
        else if( array1[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    int h = 0, w = 0;
    //scanf("%d %d", h, w);
    cin >> h >> w;

    vector< vector<int> > a;
    for (int i = 0; i < h; i++){
        vector<int> a_rows;
        for (int j = 0; j < w; j++)
        {
            int curV = -2;
            cin >> curV;
            a_rows.push_back(curV);
        }
        a.push_back(a_rows);
    }
    int target = -1;
    cin >> target;
    if(Find(target, a)){
        cout << "true"<<endl;
    }else
    {
        cout << "false" << endl;
    }
    return 0;
}
/*
3 4
1 3 5 9
2 4 6 10
3 6 7 12
6
8
*/
