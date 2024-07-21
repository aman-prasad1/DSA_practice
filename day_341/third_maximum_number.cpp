class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long large, larger, largest;
        large = larger = largest = LLONG_MIN;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > largest){
                large = larger;
                larger = largest;
                largest = nums[i];
            }
            else if(nums[i] > larger && nums[i] < largest){
                large = larger;
                larger = nums[i];
            }
            else if(nums[i] >= large && nums[i] < larger){
                large = nums[i];
            }
        }
        
        return (large == LLONG_MIN)? largest : large;
    }
};
