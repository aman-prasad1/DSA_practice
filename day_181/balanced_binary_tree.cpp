class Solution {
public:
    bool dfs(TreeNode* root , int &h){
        if(root == NULL){
            h = -1;
            return true;
        }
        int l = 0;
        int r = 0;

        if (!dfs(root->left, l) || !dfs(root->right, r)) {
            return false;
        }
        
        if (abs(l - r) > 1) {
            return false;
        }
        
        h = 1 + max(l, r);
        
        return true;
    }   
    bool isBalanced(TreeNode* root) {
        int h = 0 ;
        return dfs(root , h);
    }
};