// APPROACH 1:
class Solution {
    vector<int> arr;
    void saveToArr(TreeNode* root){
        if(!root) return;

        saveToArr(root->left);
        arr.push_back(root->val);
        root->val = arr.size()-1;
        saveToArr(root->right);
    }
    void saveToTree(TreeNode* root){
        if(!root) return;

        saveToTree(root->left);
        root->val = arr[root->val];
        saveToTree(root->right);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        saveToArr(root);

        for(int i=arr.size()-2; i>=0; i--){
            arr[i] += arr[i+1];
        }
        
        saveToTree(root);

        return root;
    }
};

// APPROACH 2:
class Solution {
    int sum = 0;
    void solve(TreeNode* root){
        if(!root) return;

        solve(root->right);
        sum += root->val;
        root->val = sum;
        solve(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};
