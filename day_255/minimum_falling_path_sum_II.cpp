class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> curr_dp = grid[0];

        for(int row=1; row<n; row++){
            vector<int> next_dp(n, INT_MAX);
            for(int currCol=0; currCol<n; currCol++){
                for(int prevCol=0; prevCol<n; prevCol++){
                    if(prevCol != currCol){
                        next_dp[currCol] = min(next_dp[currCol], grid[row][currCol] + curr_dp[prevCol]);
                    }
                }
            }
            curr_dp = next_dp;
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, curr_dp[i]);
        }
        return ans;
    }
};
