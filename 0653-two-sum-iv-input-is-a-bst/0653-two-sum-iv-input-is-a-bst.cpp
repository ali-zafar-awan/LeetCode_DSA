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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);
        int s = vec.size();
        for(int i =0;i<s;i++){
            for(int j =i+1;j<s;j++){
            if(vec[i]+vec[j]==k){
                return true;
            }
            }
        }
        return false;
    }
    vector<int> inorder(TreeNode *root, vector<int> &vec)
    {
        if (root == nullptr)
        {
            return vec;
        }
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
        return vec;
    }
};