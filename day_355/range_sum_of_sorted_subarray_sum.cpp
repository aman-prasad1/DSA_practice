/* calculated sums of all subarrays and stored it in an array -> sort it and return sum of the values form index left to right */

class Solution {
    int mod = 1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        vector<int> sums;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        sort(sums.begin(), sums.end());
        int ans = 0;
        for(int i=left-1; i<right; i++){
            ans = (ans + sums[i]) % mod;
        }

        return ans;
    }
};
