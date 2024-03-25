class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i=0; i<n; i++){
            int temp = abs(nums[i]);
            if(nums[temp-1] < 0){
                ans.push_back(temp);
            }
            nums[temp-1] *= -1;
        }
        return ans;
    }
};