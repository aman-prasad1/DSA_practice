class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int minInd = -1;
        int maxInd = -1;
        int ind = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                ind = i;
            }

            if(nums[i] == minK) minInd = i;
            if(nums[i] == maxK) maxInd = i;

            long long smaller = min(minInd, maxInd);
            long long temp = smaller - ind;

            ans += temp <= 0 ? 0 : temp;
        }
        return ans;
    }
};