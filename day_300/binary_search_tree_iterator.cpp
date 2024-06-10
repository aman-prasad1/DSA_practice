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
class BSTIterator {
    TreeNode* root;
    vector<int> tree;
    int i = 0;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        tree.push_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        inorder(root);
    }
    
    int next() {
        if(i < tree.size()) return tree[i++];
        return -1;
    }
    
    bool hasNext() {
        if(i < tree.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
