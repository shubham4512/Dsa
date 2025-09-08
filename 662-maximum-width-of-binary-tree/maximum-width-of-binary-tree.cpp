/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     unsigned long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(unsigned long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(unsigned long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unsigned long long widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        unsigned long long ans =0;
        queue<pair<TreeNode* ,unsigned long long >>q;
        q.push({root ,0});
        while(!q.empty()){
        unsigned long long size =q.size();
        unsigned long long mmin =q.front().second;
        unsigned long long first ,last;
        for(unsigned long long i=0; i<size; i++){
            unsigned long long cur_id =q.front().second-mmin;
            TreeNode* node =q.front().first;
            q.pop();
            if(i==0)first =cur_id;
            if(i ==size-1)last =cur_id;
            if(node->left){
                q.push({node->left ,cur_id*2+1});
            }
            if(node->right){
                q.push({node->right ,cur_id*2+2});
            }
                    }
                    ans =max(ans,last-first+1);
        }
        return ans;
    }
};