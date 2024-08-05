class Solution {
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> left_max = solve(root->left);
        pair<int,int> right_max = solve(root->right);

        int include = root->val + left_max.second + right_max.second;
        int exclude = max(left_max.first, left_max.second) + max(right_max.first, right_max.second);

        return {include, exclude};
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};