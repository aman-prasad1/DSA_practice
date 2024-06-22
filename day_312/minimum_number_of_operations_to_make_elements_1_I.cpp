class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flip = 0;
        
        for(int i=0; i<n-2; i++){
            if(nums[i] == 0){
                flip++;
                for(int j=i; j<i+3; j++){
                    nums[j] = (nums[j] == 1)? 0:1;
                }
            }
        }
        if(nums[n-1] == 0 || nums[n-2] == 0) return -1;
        return flip;
    }
};
