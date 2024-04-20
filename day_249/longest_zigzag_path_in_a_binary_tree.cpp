class Solution {
    int ans = 0, maxi = 0;

    void solve(TreeNode* root, int left, int right){
        if(!root) return;

        ans = max(ans, max(left, right));
        solve(root->left, 0, left+1);
        solve(root->right, right+1, 0);
    }
public:
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;

        solve(root, 0, 0);
        return ans;
    }
};