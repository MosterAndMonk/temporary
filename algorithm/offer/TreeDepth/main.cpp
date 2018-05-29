#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size() <= 0 || vin.size() <= 0)
        return NULL;
    TreeNode* curN = new TreeNode( pre[0]);
    int i = 0;
    for(; i < vin.size(); i++){
        if( pre[0] == vin[i]){
            break;
        }
    }
/*
    cout << endl << "pre ";
    for(int j = 0; j < pre.size(); j++)
    {
        cout << pre[j];
    }
    cout << endl << "vin ";
    for(int j = 0; j < pre.size(); j++)
    {
        cout << vin[j];
    }
    cout << endl << "i " << i;
*/
    if(i >= 1){
        vector<int> left_pre(pre.begin()+1, pre.begin()+i+1), left_vin(vin.begin(), vin.begin()+i);
        curN->left = reConstructBinaryTree( left_pre, left_vin );
    }
    if(i+1 < pre.size()){
        vector<int> right_pre(pre.begin()+i+1, pre.end()), right_vin(vin.begin()+i+1, vin.end());
        curN->right = reConstructBinaryTree( right_pre, right_vin );
    }
    return curN;
}


int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == NULL)
        return 0;

    return 1 + max( TreeDepth(pRoot->left), TreeDepth(pRoot->right) );
}



int main()
{
    //int pre[] = {1,2,3,4,5,6,7,8}, vin[] = {8,7,6,5,4,3,2,1};
    //int pre[] = {1,2,3,4,5,6,7,8}, vin[] = {1,2,3,4,5,6,7,8};
    int pre[] = {1,2,4,7,3,5,6,8}, vin[] = {4,7,2,1,5,3,8,6};
    vector<int> vpre(pre, pre+8), vvin(vin, vin+8);
    TreeNode* tree = reConstructBinaryTree(vpre, vvin);

    cout << TreeDepth(tree);


    return 0;
}
