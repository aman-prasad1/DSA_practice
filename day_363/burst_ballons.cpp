class Solution {
    int n;
    int solve(vector<int>& nums, vector<vector<int>>& dp, int left, int right){
        if(left > right) return 0;
        if(left == right){
           return nums[left] * nums[left-1] * nums[left+1];
        }

        if(dp[left][right] != -1) return dp[left][right];

        int ans = 0;
        for(int i=left; i <= right; i++){
            int temp = nums[left-1] * nums[i] * nums[right+1];

            temp += solve(nums, dp, left, i-1) + solve(nums, dp, i+1, right);
            ans = max(ans, temp);
        }

        return dp[left][right] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(nums, dp, 1, n-2);
    }
};
