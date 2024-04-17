class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0, cnt = 1;
        int ans = 0;
        while(j<n){
            if(nums[j++]==0) cnt--;
            while(cnt<0){
                if (nums[i] == 0) {
                    cnt++; 
                }
                i++;
            }
            ans = max(ans, j-i-1);
        }
        return ans;
    }
};