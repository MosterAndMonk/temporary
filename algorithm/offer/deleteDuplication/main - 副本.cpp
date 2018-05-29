#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL){
            return pHead;
        }
        ListNode *c_p = pHead, *p_p = pHead;

        ListNode *n_p = c_p->next;
        bool isDu = false;

        while(n_p != NULL){
            while(n_p != NULL && c_p->val == n_p->val){
                n_p = n_p->next;
                isDu = true;
            }

            if(isDu){
                if(c_p == pHead){
                    pHead = p_p = n_p;
                }
                else{
                    p_p->next = n_p;
                }
                c_p = n_p;
                isDu = false;
            }
            else{
                if(c_p != pHead){
                    p_p = c_p;
                }
                c_p = c_p->next;
            }
            if(n_p != NULL)
                n_p = n_p->next;
        }

        return pHead;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
