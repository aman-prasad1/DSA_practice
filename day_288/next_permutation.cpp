class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int j = -1;

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                j = i;
                break;
            }
        }

        if(j == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i > j; i--){
            if(nums[i] > nums[j]){
                swap(nums[i] , nums[j]);
                break;
            }
        }
        reverse(nums.begin()+j+1, nums.end());
    }
};
