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
    int kthSmallest(TreeNode* root, int k) {
        int r=0,i=0;
        inorder(root,k,r,i);
        return r;
    }
    void inorder(TreeNode* root,int k,int& res,int& i){
        if(root==nullptr||i>=k){
            return;
        }
        inorder(root->left,k,res,i);
        i++;
        if(i==k){
            res=root->val;
            return;
        }
        inorder(root->right,k,res,i);
    }
};