class Solution {
    bool isPalindrome(const string& s,int i,int j, vector<vector<int>>& dp){
        if(i >= j)
            return true;

        if(s[i] != s[j])
            return false;

        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
    }
public:
    int minCut(string s) {
        int n = s.length();

        vector<int> dp(n+1, 0);
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        if(isPalindrome(s, 0, n, dp2)) return 0;

        int prev = 0;
        for(int ind=n-1; ind >= 0; ind--){
            int ans = INT_MAX;
            for(int i=ind; i < n; i++){
                if(isPalindrome(s, ind, i, dp2)){
                    ans = min(ans, 1 + dp[i+1]);
                }
            }
            dp[ind] = ans;
        }
        return dp[0]-1;
    }
};