#include <iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int v){
        this-> val = v;
        this->next = NULL;
    }
};
ListNode* insert_list(ListNode* h, int v){
    ListNode* p = h, *pre = h;
    while(p != NULL){
        if(v <= p->val){
            break;
        }
        pre = p;
        p = p->next;
    }

    ListNode* c = new ListNode(v);
    if(pre != p){
        pre->next = c;
    }
    else{
        h = c;
    }
    c->next = p;
    return h;
}

ListNode* del_list(ListNode* h, int v){
    ListNode*p = h, *pre = h;

    while(p != NULL){
        if(v == p->val){
            break;
        }
        pre = p;
        p = p->next;
    }

    if(p != NULL){
        ListNode* q = p;
        if(pre != p){
            while(q != NULL){
                if(q->val == v){
                    pre->next = q->next;

                    ListNode* del_q = q;
                    q = q ->next;
                    delete del_q;
                    del_q = NULL;
                }
            }
        }else{
            while(q != NULL){
                if(q->val == v){
                    h = h->next;

                    ListNode* del_q = q;
                    q = q ->next;
                    delete del_q;
                    del_q = NULL;
                }
            }
        }

    }
    return h;
}

ListNode* del_all_v(ListNode* h, int v){
    ListNode*p = h, *pre = h, *nex_p = h;

    while(p != NULL){
        if(v == p->val){
            if(pre != p){
                pre->next = p->next;
            }
            else{
                h = h->next;
            }
            ListNode * p_del = p;
            delete p_del;
            p_del = NULL;
        }
        pre = p;
        p = p->next;
    }
    return h;
}

/*[1,2,4]
insert 3
insert 5
insert 0
del 1
del 7
del 2
del 4
*/
/*
NULL
del 1
*/
/*
[3]
insert 4
insert 2
del 3
*/

int main()
{

    return 0;
}
