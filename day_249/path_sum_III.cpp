class Solution {
    int ans = 0;
    void solve(TreeNode* root, long long targetSum){
        if(!root) return;

        if(root->val == targetSum) ans++;

        solve(root->left, targetSum-root->val);
        solve(root->right, targetSum-root->val);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        solve(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return ans;
    }
};