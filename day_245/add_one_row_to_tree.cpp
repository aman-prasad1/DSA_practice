class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            if(level + 1 == depth){
                break;
            }
            TreeNode* front = q.front();
            q.pop();

            if(!front){
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                }
                continue;
            }

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);

        }

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(!front) continue;

            TreeNode* left = front->left;
            TreeNode* right = front->right;

            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

            front->left = newLeft;
            front->right = newRight;

            newLeft->left = left;
            newRight->right = right;
        }

        return root;
    }
};