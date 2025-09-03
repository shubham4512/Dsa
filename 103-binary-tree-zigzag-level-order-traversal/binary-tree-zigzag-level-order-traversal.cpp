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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root ==nullptr) return {};
        queue <TreeNode*> nodesqueue;
        nodesqueue.push(root);
        bool lefttoright =true;
         while(!nodesqueue.empty()){
            int size =nodesqueue.size();
            vector<int> row(size);
            for(int i =0; i<size; i++){
                TreeNode*node = nodesqueue.front();
                nodesqueue.pop();
                int index =(lefttoright) ? i:(size-1-i);
                row[index] =node->val;
                if(node ->left){
                    nodesqueue.push(node->left);
                }
                if(node->right){
                    nodesqueue.push(node->right);
                }
            }
            lefttoright =!lefttoright;
            result.push_back(row);
         }
         return result;
    }
};