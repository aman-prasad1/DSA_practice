class Solution {
    int n, m;
    int solve(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>>& dp){
        if(i == n-1 && j == m-1) return (dungeon[i][j] < 0)? -dungeon[i][j]+1 : 1;
        if(i >= n || j >= m) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(dungeon, i, j+1, dp);
        int down = solve(dungeon, i+1, j, dp);

        int required = min(left, down) - dungeon[i][j];
        return dp[i][j] = (required <= 0)? 1 : required;
    }
    int solveTab(vector<vector<int>>& dungeon){
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        dp[n][m-1] = 1;
        dp[n-1][m] = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int left = dp[i][j+1];
                int down = dp[i+1][j];

                int required = min(left, down) - dungeon[i][j];
                dp[i][j] = (required <= 0)? 1 : required;
            }
        }
        return dp[0][0];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(), m = dungeon[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(dungeon, 0, 0, dp);
        
        return solveTab(dungeon);
    }
};
