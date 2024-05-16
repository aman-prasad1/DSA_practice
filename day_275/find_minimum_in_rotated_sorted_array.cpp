class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        while(s < e){
            int mid = s + (e-s)/2;
            if(mid == s) return min(nums[s], nums[e]);
            if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]) 
                return nums[mid];
            if(nums[mid] > nums[n-1])
                s = mid+1;
            else
                e = mid-1;
        }
        return nums[s];
    }
};
