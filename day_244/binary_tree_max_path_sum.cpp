class Solution {
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left = max(solve(root->left), 0);
        int right = max(solve(root->right), 0);

        ans = max(ans, left + right + root->val);
        return max(left + root->val, right + root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root->right && !root->left) return root->val;

        int res = solve(root);
        // cout << ans;
        return max(res, ans);
    }
};