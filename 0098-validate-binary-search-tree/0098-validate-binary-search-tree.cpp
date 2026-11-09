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
    bool isValidBST(TreeNode *root)
    {
        TreeNode *p = nullptr;
        return inorderValid(root, p);
    }
    bool inorderValid(TreeNode *root, TreeNode *&prev)
    {
        if (root == nullptr)
        {
            return true;
        }
        if(!inorderValid(root->left, prev)){
            return false;
        }
        if (prev && prev->val >= root->val)
        {
            return false;
        }
        prev = root;
        return inorderValid(root->right, prev);
    }
};