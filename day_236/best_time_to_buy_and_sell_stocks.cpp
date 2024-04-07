class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int k, vector<vector<vector<int>>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(k == 0) return 0;

        if(dp[index][buy][k] != -1)
            return dp[index][buy][k];

        int profit = 0;
        if(buy){
            profit = max( (solve(index+1,0,prices, k-1, dp)-prices[index]), solve(index+1,1,prices, k, dp) );
        }
        else{
            profit = max( (solve(index+1,1,prices, k-1, dp)+prices[index]) , solve(index+1,0,prices, k, dp) );
        }

        return dp[index][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(5, -1)));
        return solve(0,1,prices, 4, dp);
    }
};