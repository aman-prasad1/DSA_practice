class Solution {
    TreeNode* findSuccessor(TreeNode* root){
        while(root->left) root = root->left;
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val < key) root->right = deleteNode(root->right, key);
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else{
            if(!root->left && !root->right) return NULL;
            if(!root->left) return root->right;
            else if(!root->right) return root->left;

            TreeNode* temp = findSuccessor(root->right);
            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};