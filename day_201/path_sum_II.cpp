class Solution {
    vector<vector<int>> ans;
    vector<int> comp;
    int target;
    void solve(TreeNode* root, int sum){
        comp.push_back(root->val);
        sum += root->val;
        if(!root->left && !root->right){
            if(sum == target){
                ans.push_back(comp);
            }
            comp.pop_back();
            return;
        }

        if(root->left) {
            solve(root->left, sum);
        }
        if(root->right){
            solve(root->right, sum);
        }
        sum -= root->val;
        comp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return {};
        }
        target = targetSum;
        solve(root, 0);
        return ans;
    }
};