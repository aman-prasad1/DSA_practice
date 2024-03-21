class Solution {
    vector<string> ans;
    void solve(TreeNode* root, string path){
        if(!root->left && !root->right){
            path += to_string(root->val);
            ans.push_back(path);
        }


        path += to_string(root->val);
        path += "->";

        if(root->left) solve(root->left, path);
        if(root->right) solve(root->right, path);

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        solve(root, "");
        return ans;
    }
};