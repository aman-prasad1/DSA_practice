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
    bool solve(TreeNode* root, int target){
        if(!root->left && !root->right){
            if(root->val == target) return true;
            else return false;
        }
        
        bool left = false, right = false;
        if(root->left)
            left = solve(root->left, target);
        if(root->right)
            right = solve(root->right, target);

        if(left)
            root->left = NULL;
        if(right)
            root->right = NULL;

        if(!root->left && !root->right && root->val == target)
            return true;
        return false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool temp = solve(root, target);
        if(temp)
            return NULL;
        return root;
    }
};
