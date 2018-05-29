#include <iostream>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int cnt = 0;
        for(int i = 0; i < data.size(); i++){
            if(k == data[i]){
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{

    return 0;
}
