class Solution {
public:
    int solve(int s, int e, vector<int>& nums){
        int prev = nums[s], prev2 = 0;
        for(int i = s + 1; i < e; i++){
            int pick = nums[i] + prev2;
            int curr = max(pick, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int firstInd = solve(0, n-1, nums);
        int secInd = solve(1, n, nums);

        return max(firstInd, secInd);
    }
};