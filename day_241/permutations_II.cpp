class Solution {
    void solve(vector<int> nums, set<vector<int>> &ans, int index){
        //base case
        if(index >= nums.size()){
            ans.insert(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(nums, ans, index+1);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums, ans, 0);

        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};