#include <iostream>
#include <queue>

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

public:
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot == NULL){
            return true;
        }
        TreeNode *l = pRoot->left, *r = pRoot->right;
        if(l == NULL && r == NULL){
            return true;
        }
        if(l != r && (l == NULL || r == NULL)){
            return false;
        }
        queue<TreeNode*> ql, qr;
        ql.push(l);
        qr.push(r);
        //int curv = ?;
        bool ret = true;
        while((!ql.empty()||!qr.empty())&&ret){
            TreeNode* curl = ql.front();
            ql.pop();
            TreeNode* curr = qr.front();
            qr.pop();

            ret &= (curl->val == curr->val);
            if(curl->left != NULL && curr->right != NULL){
                ql.push(curl->left);
                qr.push(curr->right);
            }
            else if(curl->left != NULL || curr->right != NULL){
                ret = false;
            }

            if(curl->right != NULL && curr->left != NULL){
                ql.push(curl->right);
                qr.push(curr->left);
            }
            else if(curl->right != NULL || curr->left != NULL){
                ret = false;
            }
            cout << curl->val << " " << curr->val << endl;
        }
        if(ql.empty()&&qr.empty()){
            return ret;
        }
        else{
            return false;
        }
    }

    TreeNode* build_tree(int* vec, int n, int i){
        if(i >= n)
            return NULL;
        TreeNode * r = new TreeNode(vec[i]);
        r->left = build_tree(vec, n, (i+1)*2-1);
        r->right = build_tree(vec, n, (i+1)*2);
        return r;
    }
};


int main()
{
    int vec[15] = {8, 6, 6, 5, 7, 7, 5, 3, 4, 1, 2, 2, 1, 4, 3};
    Solution sl;
    TreeNode* r = sl.build_tree(vec, 15, 0);
    cout << sl.isSymmetrical(r) << endl;

    return 0;
}
