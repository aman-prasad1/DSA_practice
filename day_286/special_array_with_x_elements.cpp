class Solution {
    int count(vector<int>& nums, int target){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= target){
                return nums.size() - i;
            }
        }
        return 0;
    }
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int s = 0, e = nums.size();
        while(s <= e){
            int mid = s + (e-s)/2;
            int cnt = count(nums, mid);

            if(cnt == mid) return mid;
            else if(cnt > mid) s = mid+1;
            else e = mid-1;
        }
        return -1;
    }
};