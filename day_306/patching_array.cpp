class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int size = nums.size();
        long long sum = 0;
        int patch = 0;
        int i = 0;
        while(sum < n){
            if(i < size && sum+1 >= nums[i]){
                sum += nums[i];
                i++;
            }
            else{
                patch++;
                sum += sum+1;
            }
        }
        return patch;
    }
};
