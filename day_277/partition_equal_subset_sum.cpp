class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 2) return false;

        sum /= 2;
        vector<int> dp(sum+1, false);
        dp[0] = true;

        for(int num : nums){
            for(int t = sum; t > 0; t--){
                if(t >= num){
                    dp[t] = dp[t] || dp[t-num];
                }
            }
        }
        return dp[sum];
    }
};
