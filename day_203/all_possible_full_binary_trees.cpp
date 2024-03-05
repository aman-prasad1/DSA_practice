class Solution {
    unordered_map<int, vector<TreeNode*>> mp;
public:
    
    vector<TreeNode*> solve(int n) {

        if(n%2 == 0)
            return {};
        
        if(n == 1) {
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        
                
        if(mp[n].size() != 0)
            return mp[n];
        
        
        vector<TreeNode*> ans;
        
        for(int i = 1; i<n; i += 2) {
            
            vector<TreeNode*> leftTree  = solve(i);
            vector<TreeNode*> rightTree = solve(n-i-1);
            
            for(auto &l : leftTree) {
                
                for(auto &r : rightTree) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
            
        }
        
        return mp[n] = ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};