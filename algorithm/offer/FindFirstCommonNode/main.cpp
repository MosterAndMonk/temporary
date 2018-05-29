#include <iostream>
#include <stack>

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*> s1, s2;
        for(ListNode* p1 = pHead1; p1 != NULL; p1 = p1->next){
            s1.push(p1);
        }
        for(ListNode* p2 = pHead2; p2 != NULL; p2 = p2->next){
            s2.push(p2);
        }
        ListNode* ans = NULL;
        while(!s1.empty() && !s2.empty() && (s1.top() == s2.top())){
            ans = s1.top();
            s1.pop();
            s2.pop();
        }
        return ans;
    }
};

void printl(ListNode* h){
    for(ListNode* p = h; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}

int main()
{
    int a[5] = {4, 5, 2, 3, 6};
    int b[4] = {1, 2, 3, 6};
    ListNode* cmn = NULL, *h1 = NULL;
    ListNode* p = h1;
    ListNode* q = h1;
    bool first = false;
    for(int i = 0; i < 5; i++){
        p = new ListNode(a[i]);
        if(a[i] == 2){
            cmn = p;
        }
        if(!first){
            h1 = p;
            q = p;
            first = true;
        }
        else{
            q -> next = p;
            q = p;
        }

    }
    ListNode *h2 = new ListNode(1);
    h2-> next = cmn;
    //printl(h2);
    Solution sl;
    //p = sl.FindFirstCommonNode(h1, h2);
    p = sl.FindFirstCommonNode(NULL, NULL);
    cout << p->val;
    return 0;
}
