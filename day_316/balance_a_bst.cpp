class Solution {
    vector<int> arr;
    void setArr(TreeNode* root){
        if(!root) return;

        setArr(root->left);
        arr.push_back(root->val);
        setArr(root->right);
    }
    TreeNode* createBST(int start, int end){
        if(start > end) return NULL;

        int mid = start+(end-start)/2;
        TreeNode* node = new TreeNode(arr[mid]);

        node->left  = createBST(start, mid-1);
        node->right = createBST(mid+1, end);

        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        setArr(root);
        TreeNode* ans = createBST(0, arr.size()-1);
        return ans;
    }
};
