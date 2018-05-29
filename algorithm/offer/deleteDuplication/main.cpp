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
        ListNode* new_pHead = new ListNode(-1);
        new_pHead->next = pHead;

        ListNode *c_p = pHead, *p_p = new_pHead, *n_p = pHead->next;
        bool isDu = false;

        while(n_p != NULL){
            while(n_p != NULL && c_p->val == n_p->val){
                n_p = n_p->next;
                isDu = true;
            }
            if(isDu){
                //重复了
                p_p->next = n_p;
                isDu = false;
            }
            else{
                //没有重复
                p_p = p_p->next;
            }
            c_p = n_p;
            if(n_p != NULL){
                n_p = n_p->next;
            }
        }
        //delete new_pHead;
        return new_pHead->next;
    }

    ListNode* deleteDuplication1(ListNode* pHead)
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
