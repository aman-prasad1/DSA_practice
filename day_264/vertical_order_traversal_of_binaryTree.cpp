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
    map<int,multiset<pair<int,int>> > mp;
    void solve(TreeNode* root, int left, int right){
        mp[right-left].insert({left+right , root->val});
        if(root->left) solve(root->left, left+1, right);
        if(root->right) solve(root->right, left, right+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        solve(root, 0, 0);

        for(auto &[key,vec]:mp){
            vector<int> temp;
            for(auto &[x,y]:vec){
                temp.push_back(y);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
