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
    TreeNode*prev =nullptr;
    bool inorder(TreeNode*root){
        if(!root)return true;
        //left side if the tree
        if (!inorder(root->left)) return false;
        if(prev &&root->val <=prev->val) return false;
        prev =root;
        //right side if the tree
        return inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        prev =nullptr;
        return inorder(root);
    }
};