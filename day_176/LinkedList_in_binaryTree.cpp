class Solution {
    bool solve(ListNode* head, TreeNode* root){
        if(!head) return true;
        if(!root) return false;

        bool left = false;
        bool right = false;
        if(head->val == root->val){
            left = solve(head->next, root->left);
            right = solve(head->next, root->right);
            return left || right;
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;

        bool ans = solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
        return ans;
    }
};