class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 1, maxSum = root->val;
        int currLevel = 1, currSum = root->val;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(!front){
                if(!q.empty()) q.push(NULL);
                if(maxSum < currSum){
                    maxSum = currSum;
                    maxLevel = currLevel;
                }
                currSum = 0;
                currLevel++;
                continue;
            }

            currSum += front->val;

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

        return maxLevel;
    }
};