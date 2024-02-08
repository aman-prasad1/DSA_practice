class Solution {
    // dp + memoization
    int solve(int n, int maxi, vector<vector<int>>& dp){
        if(n == 0) return 1;
        if(n < 0) return 10000;

        if(dp[n][maxi] != -1) return dp[n][maxi];

        int ans = 10000;
        for(int i=maxi; i>0; i--){
            int sq = i*i;
            if(n >= sq){
                ans = min(ans, 1 + solve(n-sq, i,dp));
            }
        }
        return dp[n][maxi] = ans;
    }

    // BFS
    int bfs(int n){
        vector<int> dp(n+1, 10001);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j <= i; j++){
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        // if(n == 1) return 1;

        // // finding nearest square to n
        // int maxi = 1;
        // while(maxi*maxi < n){
        //     maxi++;
        // }

        // if(maxi*maxi == n) return 1;
        // maxi -= 1;

        // vector<vector<int>> dp(n+1,vector<int>(maxi+1, -1));

        // int ans = solve(n, maxi, dp);

        // return ans-1;

        int ans = bfs(n);
        return ans;

    }
};