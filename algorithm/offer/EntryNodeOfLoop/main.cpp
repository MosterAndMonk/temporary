#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
private:
    vector<ListNode*> v_listp;
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *p2 = pHead, *p = pHead;

        while(p != NULL && p->next != NULL){
            p = p->next;
            p2 = p2->next;
            p2 = p2->next;

            if(p == p2){
               p = pHead;
               while(p != p2){
                   p = p->next;
                   p2 = p2->next;
               }
               return p;
            }
        }
        return NULL;
    }

    ListNode* EntryNodeOfLoop1(ListNode* pHead)
    {
        ListNode* ans_p = NULL;
        for(ListNode* p = pHead; p != NULL && ans_p == NULL; p = p->next){
            for(uint8_t i = 0; i < v_listp.size(); i++){
                if(v_listp[i] == p){
                    ans_p = p;
                }
            }
            v_listp.push_back(p);
        }

        return ans_p;
    }

};

int main()
{
    ListNode* h = new ListNode(1);
    ListNode* p = h;
    for(int i = 2; i <= 5; i++){
        p->next = new ListNode(i);
    }
    p->next->next = h;
    Solution sl;
    p = sl.EntryNodeOfLoop(h);
    cout << p->val;

    return 0;
}
