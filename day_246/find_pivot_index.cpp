class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        preSum[0] = nums[0];
        int ans = -1;
        for(int i=1; i<n; i++){
            preSum[i] = preSum[i-1] + nums[i];
        }

        int sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += nums[i];
            if(preSum[i] - sum == 0) ans = i;
        }
        return ans;
    }
};