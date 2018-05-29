#include <iostream>
#include <deque>
#include <cstdio>
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

class Solution {
deque<TreeNode*> q;
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector< vector<int> > ans;
        if(pRoot == NULL){
            return ans;
        }

        vector<int> level_node;
        int n[15] = {0, 1, 2};
        int d_n = 1, d_level = 1;
        TreeNode * c;
        q.push_back(pRoot);

        while(!q.empty()){
            c = q.front();
            level_node.push_back(c->val);

            if(c->left != NULL){
                q.push_back(c->left);
            }
            else{
                n[d_level+1]--;
            }

            if(c->right != NULL){
                q.push_back(c->right);
            }
            else{
                n[d_level+1]--;
            }

            //printf("d_level=%d n[d_level]=%d val=%d\n", d_level, n[d_level], c->val);
            q.pop_front();
            d_n--;
            if(d_n == 0){
                d_level++;
                d_n = n[d_level];
                n[d_level+1] = 2*n[d_level];
            }

        }

        int k = 0, temp_n = 0;
        for(int i = 1; i <= d_level && k <= level_node.size() && n[i]; i++){
            vector<int> temp;
            if(i % 2 != 1){
                k += n[i];
            }
            for(int j = 0; j < n[i] && k <= level_node.size(); j++){
                if(i % 2 == 1){
                    temp.push_back(level_node[k]);
                    k++;
                }
                else{
                    temp.push_back(level_node[k-j-1]);
                    //cout << "temp_n-j=" << k-j-1 << " level_node[temp_n-j]=" << level_node[k-j-1]<<endl;
                }
            }

            ans.push_back(temp);
        }
        return ans;
    }
    //int t_n = 0;
    TreeNode* build_tree(int* vec, int i, int n){
        if(i >= n)
            return NULL;
        if(vec[i] == '#'){
            return NULL;
        }
        TreeNode * r = new TreeNode(vec[i]);
        //t_n++;
        r->left = build_tree(vec, (i+1)*2-1, n);
        r->right = build_tree(vec, (i+1)*2, n);
        return r;
    }
};

int main()
{
    Solution sl;
    /*
    int vec[7] = {8, 6, 10, 5, 7, 9, 11};
    TreeNode* r = sl.build_tree(vec, 0, 7);
    */
    int vec[14] = {8, 6, 10, 5, 7, 9, 11, 12, 13, 14, 15, 16, 17, 18};
    TreeNode* r = sl.build_tree(vec, 0, 14);

    vector<vector<int> > ans = sl.Print(r);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
