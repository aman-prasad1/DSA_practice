class Solution {
    int solve(vector<int>& prices, int fee, int ind, int buy, vector<vector<int>>& dp){
        if(ind >= prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit = max(solve(prices, fee, ind+1, 0, dp) - prices[ind], solve(prices, fee, ind+1, 1, dp));
        }
        else{
            profit = max(solve(prices, fee, ind+1, 1, dp) + prices[ind] - fee, solve(prices, fee, ind+1, 0, dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        int ans = solve(prices, fee, 0, 1, dp);

        return ans;
    }
};
