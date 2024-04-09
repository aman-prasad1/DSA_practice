class Solution {
    int solve(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(ind >= coins.size() || amount <= 0){
            return amount == 0 ? 0 : INT_MAX-1;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int include = 0, exclude = 0;
        if(coins[ind] > amount){
            exclude = solve(ind+1, coins, amount, dp);
            return dp[ind][amount] = exclude;
        }
        else{
            include = 1 + solve(ind, coins, amount-coins[ind], dp);
            exclude = solve(ind+1, coins, amount, dp);
        }
        return dp[ind][amount] = min(include , exclude);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = solve(0, coins, amount, dp);
        if(ans == INT_MAX-1) return -1;
        return ans;
    }
};