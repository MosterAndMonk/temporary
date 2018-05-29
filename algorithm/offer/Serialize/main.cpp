#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <string>
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
    char* Serialize(TreeNode *root) {
        if(root == NULL){
            return NULL;
        }
        queue<TreeNode *> q;
        q.push(root);

        int l = 200;
        char* buf = new char[l];
        memset(buf, 0, l);

        int j = 0;

        while(!q.empty()){
            TreeNode* c = q.front();
            if(c != root){
                j += sprintf(buf+j, ",");
            }
            if(c == NULL){
                j += sprintf(buf+j, "#");
            }
            else{
                j += sprintf(buf+j, "%d", c->val);

                if(c->left != NULL || c->right != NULL){
                    q.push(c->left);
                    q.push(c->right);
                }
            }
            q.pop();
        }
        return buf;
    }

    TreeNode* Deserialize(char *str) {
        if(str == NULL){
            return NULL;
        }
        if(strlen(str) == 0){
            return NULL;
        }

        vector<string> v;
        splitString(str, v, ",");

        TreeNode *r = NULL;
        if(v[0] != "#"){
            TreeNode *c = new TreeNode(atoi(v[0].c_str()));
            r = c;
            int i = 1;
            queue<TreeNode *> q;
            q.push(c);

            while(i < v.size()/*|| !q.empty()*/){
                c = q.front();

                if(v[i] != "#"){
                    int val = atoi(v[i].c_str());
                    c->left = new TreeNode(val);
                    q.push(c->left);
                }
                i++;

                if(v[i] != "#"){
                    int val = atoi(v[i].c_str());
                    c->right = new TreeNode(val);
                    q.push(c->right);
                }
                i++;

                q.pop();
            }
        }
        return r;
    }

    void splitString(const string s, vector<string> & v, const string c){
        string::size_type pos1, pos2;
        pos1 = 0;
        pos2 = s.find(c);
        while(pos2 != string::npos){
            v.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2 + c.size();//c.length();
            pos2 = s.find(c, pos1);



        }
        if(pos1 != s.length()){
            v.push_back(s.substr(pos1, s.length()-pos1));
        }
    }
};

int main()
{
    Solution sl;
    //char * s = "5,#,4,#,3,#,2";
    char * s = "5,4,#,3,#,2,#";
    TreeNode* r = sl.Deserialize(s);
    cout << sl.Serialize(r) << endl;
    return 0;
}
