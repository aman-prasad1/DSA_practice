class Solution {
    int solve(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(j >= t.size()) {
            return dp[i][j] = 1;
        }
        if(i >= s.size()) return dp[i][j] = 0;

        if(dp[i][j] != -1) return dp[i][j];

        int include = 0, exclude = 0;
        if(s[i] == t[j]){
            // include
            include = solve(i+1, j+1, s, t, dp);
            //exclude
            exclude = solve(i+1, j, s, t, dp);
        }
        else{
            exclude = solve(i+1, j, s, t, dp);
        }

        return dp[i][j] = include + exclude;
    }

    int solveTab(string s, string t){
        vector<vector<double>> dp(s.size()+1, vector<double>(t.size()+1, 0));
        for(int j=1; j<=t.size(); j++){
            dp[s.size()][j] = 0;
        }
        for(int i=0; i<=s.size(); i++){
            dp[i][t.size()] = 1;
        }

        for(int i=s.size()-1; i>=0; i--){
            for(int j=t.size()-1; j>=0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
    
        return dp[0][0];
    }
public:
    int numDistinct(string s, string t) {
        // MEMOIZATION SOLUTION
            // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
            // int ans = solve(0, 0, s, t, dp);

        // TABULATION SOLUTION
            int ans = solveTab(s, t);
        return ans;
    }
};