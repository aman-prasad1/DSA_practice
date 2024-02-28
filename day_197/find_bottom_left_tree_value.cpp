class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int ans = root->val;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(!front){
                if(!q.empty()){
                    ans = q.front()->val;
                    q.push(NULL);
                }
                continue;
            }

            if(front->left)
                q.push(front->left);

            if(front->right)
                q.push(front->right);
        }

        return ans;
    }
};