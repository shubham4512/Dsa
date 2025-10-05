/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int cnt=0;
int maxcnt =0;
int preval =INT_MIN;
vector<int> result;
bool firstnode =true;
void inorder(TreeNode*root){
    if(!root) return;
    inorder(root->left);
    if(firstnode){
        cnt =1;
        firstnode =false;
    }
    else{ 
        if(root->val ==preval){
            cnt++;
        } else{
            cnt =1;
        }
    }
    if(cnt > maxcnt){
        result.clear();
        result.push_back(root->val);
        maxcnt =cnt;
    }
    else if(cnt ==maxcnt){
        result.push_back(root->val);
    }
    preval =root->val;
    inorder(root->right);
}
   vector<int> findMode(TreeNode* root) {
     inorder(root);
     return result;   
    }
};