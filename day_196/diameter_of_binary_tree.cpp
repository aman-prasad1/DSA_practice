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
    int solve(TreeNode* root, int& maxi){
        if(!root) return 0;

        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);

        maxi = max(maxi, left+right);
        return max(left, right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root->right && !root->left) return 0;

        int maxi = 0;
        int max_dist = solve(root, maxi);

        return maxi;
    }
};