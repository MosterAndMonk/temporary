#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    unsigned char hash_t[128];
    queue<int> q;
  //Insert one char from stringstream
    void Insert(char ch)
    {
        ++hash_t[ch-'\0'];
        if(hash_t[ch-'\0'] == 1){
            q.push(ch-'\0');
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty()){
            int c = q.front();
            if(hash_t[c] == 1){
                return c;
            }
            if(hash_t[c] >= 2){
                q.pop();
            }
        }
        return '#';
    }

};

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
