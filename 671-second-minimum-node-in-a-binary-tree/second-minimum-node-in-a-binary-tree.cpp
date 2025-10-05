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
    int findsecondmin(TreeNode*root ,int firstmin){
        if(!root)return -1;
        if(root->val >firstmin) return root->val;
        int left =findsecondmin(root->left ,firstmin);
         int right =findsecondmin(root->right ,firstmin);
         if(left ==-1)return right;
         if(right ==-1)return left;
         return min(left,right);

    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        return findsecondmin(root ,root->val);
    }
};