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
    bool f(TreeNode* node, TreeNode* cur, int target) {
        if (node == nullptr) 
        {
            return false;
        }
        if (node != cur && node->val == target){
            return true;
        }
        return f(node->left, cur, target) || f(node->right, cur, target);
    }

    bool inorder(TreeNode* root, TreeNode* top, int k) {
        if (root == nullptr) {
            return false;
        }
        if (inorder(root->left, top, k)) {
            return true;
        }
        if (f(top, root, k - root->val)) {
            return true;
        }
        return inorder(root->right, top, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return inorder(root, root, k);
    }
};