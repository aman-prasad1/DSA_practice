#define mod 1000000007
class Solution {
    int solve(int n, vector<int>& dp){
        if(n < 0) return 0;
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = ((solve(n-1, dp)*2)%mod + solve(n-3, dp))%mod;

        return dp[n] = ans;
    }
public:
    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return solve(n, dp);
    }
};