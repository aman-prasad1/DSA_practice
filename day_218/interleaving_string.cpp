class Solution {
    int n, m;
    bool solve(string s1, string s2, string s3, int i, int j, vector<vector<int>>& dp){
        if(i >= n && j >= m) return true;

        if(dp[i][j] != -1) return dp[i][j];
        bool first = false;
        bool second = false;
        if(i < n && s1[i] == s3[i+j]){
            first = solve(s1, s2, s3, i+1, j, dp);
        }
        if(j < m && s2[j] == s3[i+j]){
            second = solve(s1, s2, s3, i, j+1, dp);
        }

        return dp[i][j] = first || second;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        if(m + n != s3.size()) return false;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, s3, 0, 0, dp);
    }
};