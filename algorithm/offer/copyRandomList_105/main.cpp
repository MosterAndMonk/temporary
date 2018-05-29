#include <iostream>

using namespace std;

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode* p = head;
        RandomListNode* h = NULL, *c_p = NULL;

        while(p != NULL){
            RandomListNode* cur_p = new RandomListNode(p->label);
            if(h == NULL){
                h = cur_p;
                c_p = cur_p;
            }
            else{
                c_p->next = cur_p;
                c_p = cur_p;
            }
            p = p->next;
        }

        p = head;
        c_p = h;
        while(p != NULL){

            if(p->random != NULL){
                RandomListNode* r_p = head, *c_r_p = h;
                while(p->random != r_p){
                    r_p = r_p->next;
                    c_r_p = c_r_p->next;
                }
                c_p->random = c_r_p;
            }
            else{
                c_p->random = NULL;
            }
            p = p->next;
            c_p = c_p->next;
        }

        return h;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
