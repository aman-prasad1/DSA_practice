class Solution {
    void inorder(TreeNode* root, vector<TreeNode*>& nodes){
        if(root==NULL) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        for(int i=0; i<nodes.size()-1; i++){
            if(nodes[i]->val > nodes[i+1]->val){
                first = nodes[i];
                break;
            }
        }
        for(int i=nodes.size()-1; i>0; i--){
            if(nodes[i]->val < nodes[i-1]->val){
                second = nodes[i];
                break;
            }
        }
        swap(first->val, second->val);
    }
};