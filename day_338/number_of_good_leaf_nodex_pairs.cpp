class Solution {
public:

    vector<int> solve(TreeNode* root, int distance, int &cnt){
        if(!root) return {0};

        if(!root->left && !root->right) return {1};

        vector<int> left = solve(root->left, distance,cnt);
        vector<int> right = solve(root->right,distance,cnt);

        for(int x: left){
            for(int y: right){
                if(x > 0 && y>0){
                    if(x+y <= distance) cnt++;
                }
            }
        }

        vector<int> ans;
        for(int x: left){
            if(x>0 && x<distance){
                ans.push_back(x+1);
            }
        }

        for(int x: right){
            if(x>0 && x<distance){
                ans.push_back(x+1);
            }
        }

        return ans;
        
    }

    int countPairs(TreeNode* root, int distance) {

        int cnt = 0;
        solve(root,distance,cnt);

        return cnt;
        
    }
};