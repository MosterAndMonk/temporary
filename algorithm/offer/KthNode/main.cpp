#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
    stack< TreeNode* > st;
    TreeNode* p;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        p = NULL;

        n_big(pRoot, k);

        return p;
    }

    void n_big(TreeNode* r, int k){
        if(r == NULL){
            return;
        }
        if(r->left == NULL && r->right == NULL){

            st.push(r);
            if(k == st.size()){
                if(p == NULL){
                    p = st.top();
                }
            }

            return;
        }

        n_big(r->left, k);

        st.push(r);
        if(k == st.size()){
            if(p == NULL){
                p = st.top();
            }
        }

        n_big(r->right, k);

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
