class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int ans = 0;

        int i = 0, j = 0;

        while(j < n){
            while(j < n && cnt <= k){
                if(nums[j] == 0){
                    cnt++;
                }
                j++;
            }
            if(cnt <= k && j == n) ans = max(ans, j-i);
            else ans = max(ans, j-i-1);

            while(i < j && cnt > k){
                if(nums[i] == 0){
                    cnt--;
                }
                i++;
            }
        }
        return ans;
    }
};