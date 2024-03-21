class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int s = 0, e = n-1, mid = (e-s)/2 + s;

        while(s < e){
            if(e == 1){
                return (nums[0] > nums[1])? 0 : 1;
            }
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            if(nums[mid+1] > nums[mid]) s = mid+1;
            else if(nums[mid-1] > nums[mid]) e = mid-1;

            mid = (e-s)/2 + s;
        }

        return s;
    }
};