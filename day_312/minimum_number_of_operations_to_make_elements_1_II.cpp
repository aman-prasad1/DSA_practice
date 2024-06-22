class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flip = 0;
        
        for(int i=0; i<n; i++){
            int isFliped = flip%2;
            if((nums[i] == 1 && isFliped == 1) || (nums[i] == 0 && isFliped == 0)){
                flip++;
            }
            
        }
        return flip;
    }
};
