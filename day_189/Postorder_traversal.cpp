class Solution {
    void solve(TreeNode* root, vector<int>& ans){
        if(!root) return;

        solve(root->left, ans);
        solve(root->right, ans);

        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        solve(root, ans);

        return ans;
    }
};