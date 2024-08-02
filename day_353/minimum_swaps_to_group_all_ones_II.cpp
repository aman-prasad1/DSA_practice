class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int total_ones = 0;
        for(int i=0; i<n; i++) total_ones += nums[i];
        
        int window = 0, max_window = 0;
        int l = 0, r = 0;

        while(r < 2*n){
            if(nums[r % n] == 1) window++;

            if(r - l + 1 > total_ones){
                window -= nums[l % n];
                l++;
            }

            max_window = max(max_window, window);
            r++;
        }

        return total_ones - max_window;
    }
};
