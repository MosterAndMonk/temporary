#include <iostream>
#include <list>

using namespace std;

class MinStack {
public:
    list<int> min_l;
    int min_v;

    MinStack() {
        // do intialization if necessary
        min_v = 1 << 30;
        min_l.clear();
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        min_l.push_back(number);
        if(number < min_v){
            min_v = number;
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int ret = 1 << 30;
        if(min_l.size() != 0){
            ret = min_l.back();
            min_l.pop_back();

            if(ret == min_v){
                int min_tmp = 1 << 30;
                for(auto p = min_l.begin(); p != min_l.end(); p++){
                    int v_tmp = (*p);
                    min_tmp = min(min_tmp, v_tmp);
                }
                min_v = min_tmp;
            }
        }
        return ret;
    }

    int min(int v1, int v2){
        if(v1 < v2){
            return v1;
        }
        else{
            return v2;
        }
    }
    /*
     * @return: An integer
     */
    int min() {
        return min_v;
        // write your code here
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
