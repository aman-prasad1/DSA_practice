class Solution {
    int m, n;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i >= m || i < 0 || j >= n || j < 0) return INT_MIN;

        if(dp[i][j] != -1) return dp[i][j];

        int up = 0, down = 0, left = 0, right = 0;
        // up
        if(i-1 >= 0 && matrix[i][j] < matrix[i-1][j])
            up = 1 + solve(i-1, j, matrix, dp);

        // down
        if(i+1 < m && matrix[i][j] < matrix[i+1][j])
            down = 1 + solve(i+1, j, matrix, dp);

        // left
        if(j-1 >= 0 && matrix[i][j] < matrix[i][j-1])
            left = 1 + solve(i, j-1, matrix, dp);

        // right
        if(j+1 < n && matrix[i][j] < matrix[i][j+1])
            right = 1 + solve(i, j+1, matrix, dp);

        return dp[i][j] = max(up, max(down, max(left, right)));
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int path = solve(i, j, matrix, dp);
                ans = max(ans, path);
            }
        }

        return ans + 1;
    }
};