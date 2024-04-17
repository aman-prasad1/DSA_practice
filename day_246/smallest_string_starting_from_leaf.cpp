class Solution {
    vector<string> res;
    void solve(TreeNode* root, string str){
        str += root->val + 'a';
        if(!root->left && !root->right){
            string temp = str;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }

        if(root->left) solve(root->left, str);
        if(root->right) solve(root->right, str);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");

        sort(res.begin(), res.end());
        return res[0];
    }
};