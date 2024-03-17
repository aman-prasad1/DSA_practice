class Solution {
public:
    int solve(TreeNode* root) {
        if(!root->left && !root->right) return root->val;

        int left = 0, right = 0;

        if(root->left){
            left = solve(root->left);
        }
        if(root->right && (root->right->left || root->right->right)){
            right = solve(root->right);
        }
        return left + right;
    }

    int sumOfLeftLeaves(TreeNode* root){
        if(!root->left && !root->right) return 0;

        return solve(root);
    }
};