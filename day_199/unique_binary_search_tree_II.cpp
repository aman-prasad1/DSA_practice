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
public:
    map<pair<int,int>,vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int s, int e){
        if(s > e) return dp[{s,e}] = {NULL};

        if(s == e){
            TreeNode* temp = new TreeNode(s);
            return dp[{s,e}] = {temp};
        }

        if(!dp[{s,e}].empty()){
            return dp[{s,e}];
        }

        vector<TreeNode*> ans;
        for(int i=s; i<=e; i++){
            vector<TreeNode*> left = solve(s, i-1);
            vector<TreeNode*> right = solve(i+1, e);

            for(auto l : left){
                for(auto r : right){
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    ans.push_back(node);
                }
            }
        }
        return dp[{s,e}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans = solve(1, n);
        return ans;
    }
};