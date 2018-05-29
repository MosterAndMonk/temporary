#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool is_balanced;
    bool IsBalanced_Solution(TreeNode* pRoot) {
        is_balanced = true;
        travel_tree(pRoot);
        return is_balanced;
    }

    int travel_tree(TreeNode* pRoot){
        if(pRoot == NULL){
            return 0;
        }
        int l = travel_tree(pRoot->left);
        int r = travel_tree(pRoot->right);
        if(-1 > (l - r) || (l - r) > 1){
            is_balanced = is_balanced && false;
        }
        return max(l, r) + 1;
    }
};

int main()
{
    Solution sl;
    //sl.IsBalanced_Solution()
    return 0;
}
