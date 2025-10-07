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
class BSTIterator{
   stack<TreeNode*>st;
   bool reverse =true;
   public:
   BSTIterator(TreeNode*root, bool isReverse){
 reverse =isReverse;
 pushAll(root);
   }
   int next(){
    TreeNode*node =st.top();
    st.pop();
    if(reverse)pushAll(node->left);
    else pushAll(node->right);
    return node->val;
   }
   bool hasnext(){
    return !st.empty();
   }
   private:
   void pushAll(TreeNode*node){
    while(node){
        st.push(node);
        node = reverse? node->right:node->left;
    }
   }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        BSTIterator l(root,false);// for the smallest
        BSTIterator r(root ,true);//for the largest
        int i =l.next();
        int j =r.next();
        while(i<j){
         int sum =i+j;
            if(sum==k)return true;
            else if(sum<k){
                if(l.hasnext())i= l.next();
                else break;
            }
            else{
                if(r.hasnext())j=r.next();
                else break;
            }
        }
        return false;
    }
};