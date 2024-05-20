// APPROACH: 1
// class Solution {
//     int solve(int ind, int ans, vector<int>& nums){
//         if(ind >= nums.size()) return ans;

//         int include = solve(ind+1, ans^nums[ind], nums);
//         int exclude = solve(ind+1, ans, nums);

//         return include + exclude;
//     }
// public:
//     int subsetXORSum(vector<int>& nums) {
//         int ans = solve(0, 0, nums);
//         return ans;
//     }
// };

// APPROACH: 2
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(int num : nums){
            ans |= num;
        }
        return ans * pow(2, nums.size()-1);
    }
};
