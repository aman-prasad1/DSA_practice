class Solution {
    long long solve(vector<vector<long long>>& dp, vector<int>& nums, int ind, int flag){
        ios::sync_with_stdio(0);
        cin.tie(0);

        if(ind < 0) return 0;
        if(ind == 0){
            if(flag == 0){
                return nums[0];
            }
            else{
                return INT_MIN;
            }
        }
        if(dp[ind][flag] != -1){
            return dp[ind][flag];
        }
        long long ans = INT_MIN;
        if(flag == 0){
            ans = max(ans, nums[ind]+solve(dp, nums, ind-1, 0));
            ans = max(ans, nums[ind]+solve(dp, nums, ind-1, 1));
        }
        else{
            ans = max(ans, -nums[ind]+solve(dp, nums, ind-1, 0));
        }
        return dp[ind][flag] = ans;
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2,-1));
        
        return max(solve(dp, nums, n-1, 0), solve(dp, nums, n-1, 1));
    }
};
