#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int cnt = 0;
        int l = data.size()-1;
        //cout << binary_find(data, 0, l, k) << endl;
        int pos = binary_find(data, 0, l, k);
        if(pos != -1){
            int ba, go;
            ba = go = pos;

            while(data[ba] == data[pos] && ba >= 0){
                ba--;
                cnt++;
            }
            while(data[go] == data[pos] && go <= l){
                go++;
                cnt++;
            }

            cnt = cnt - 1;
        }
        return cnt;
    }
    int binary_find(vector<int> data, int s, int e, int k){
        if(s > e){
            return -1;
        }
        if(k < data[s] || k > data[e]){
            return -1;
        }
        else if(k == data[s]){
            return s;
        }

        while(s < e){
            int h = s + (e-s)/2;
            if(k == data[h]){
                return h;
            }
            else if(k < data[h]){
                e = h;
            }
            else{
                s = h+1;
            }
        }

        return -1;

    }
    int binary_find1(vector<int> data, int s, int e, int k){
        if(s > e){
            return -1;
        }
        if(k < data[s] || k > data[e]){
            return -1;
        }
        int h = s + (e-s)/2;
        if(k == data[h]){
            return h;
        }
        else if(k < data[h]){
            return binary_find(data, s, h, k);
        }
        else{
            return binary_find(data, h+1, e, k);
        }
    }
};

int main()
{
    int d[5] = {3, 4, 5, 8};
    Solution sl;
    cout << sl.GetNumberOfK(vector<int>((&d[0]), (&d[0]) + 4), 6);

    return 0;
}
