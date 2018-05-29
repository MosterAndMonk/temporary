#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL){
            return NULL;
        }
        if(pNode->right == NULL){
            return get_up(pNode);
        }
        else{
            return get_left(pNode->right);
        }
    }
    TreeLinkNode* get_up(TreeLinkNode* pNode){
        if(pNode->next == NULL){
            return NULL;
        }
        if(pNode->next->left == pNode){
            return pNode->next;
        }
        else{
            return get_up(pNode->next);
        }
    }

    TreeLinkNode* get_left(TreeLinkNode* pNode){
        if(pNode->left == NULL){
            return pNode;
        }
        else{
            return get_left(pNode->left);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
