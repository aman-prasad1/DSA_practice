class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        
        set<int> prev;
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            set<int> curr;
            curr.insert(nums[i]);
            for(int it : prev) curr.insert(it & nums[i]);

            for(int it : curr) ans = min(ans, abs(k-it));

            prev = curr;
        }
        return ans;
    }
};
