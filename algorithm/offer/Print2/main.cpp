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
    queue<TreeNode*> q;
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ans;
        if(pRoot == NULL){
            return ans;
        }

        vector<int> level_node;
        int n = 1, n_n = 2;
        q.push(pRoot);

        while(!q.empty()){
            TreeNode* c = q.front();

            level_node.push_back(c->val);

            if(c->left == NULL){
                n_n--;
            }
            else{
                q.push(c->left);
            }
            if(c->right == NULL){
                n_n--;
            }
            else{
                q.push(c->right);
            }

            q.pop();
            n--;

            if(n == 0){
                if(level_node.size() > 0){
                    ans.push_back(level_node);
                    level_node.clear();
                }

                n = n_n;
                n_n *= 2;
            }
        }
        return ans;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
