#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {

        int* is_dup = new int[length];
        memset(is_dup, 0, sizeof(int)*length);

        for(int i = 0; i < length; i++){
            int cur = numbers[i];
            is_dup[cur]++;
        }

        bool ret = false;

        for(int i = 0; i < length; i++){
            if(is_dup[i] > 1){
                if(!ret){
                    ret = true;
                    *duplication = i;
                }
            }
        }

        delete [] is_dup;

        return ret;
    }
};

int main()
{
    Solution sl;
    int a[5] = {2, 3, 3, 4, 0};
    int duplication;
    cout << sl.duplicate(a, 5, &duplication) ;
    cout << " " << duplication << endl;
    cout << "Hello world!" << endl;
    return 0;
}
