class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int level = 0;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(!front){
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                }
                continue;
            }

            // for even level
            if(level%2 == 0){
                if(front->val % 2 == 0) return false;
                if(q.front() != NULL && front->val >= q.front()->val){
                    return false;
                }
            }

            // for odd level
            else{
                if(front->val % 2 != 0) return false;
                if(q.front() != NULL && front->val <= q.front()->val){
                    return false;
                }
            }

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return true;
    }
};