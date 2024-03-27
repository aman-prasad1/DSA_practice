class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return (nums[0] < k)? 1 : 0;

        int multi = 1, ans = 0, i = 0, j = 0, temp = 0;

        while(j < n && i < n){
            if(multi * nums[j] < k){
                multi *= nums[j];
                j++;
            }
            else{
                int len = j-i;
                ans += ((len * (len + 1)) / 2) - temp;
                multi /= nums[i];
                i++;
                temp = (len * (len-1))/2;
                if(i > j){
                    j = i;
                    multi = 1;
                }
            }
        }
        if(i < n){
            int len = j-i;
            ans += ((len * (len + 1)) / 2) - temp;
        }
        return ans;
    }
};