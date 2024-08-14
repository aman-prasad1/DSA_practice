class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // APPROACH 1
        // unordered_map<int,bool> mp;

        // for(int num : nums){
        //     mp[num] = true;
        // }

        // vector<int> ans;
        // for(int i=1; i <= n; i++){
        //     if(!mp[i]) ans.push_back(i);
        // }
        // return ans;


        // APPROACH 2

        for (auto num : nums){
            if( nums[abs(num)-1] > 0 ) nums[abs(num)-1] *= -1;
        }

        vector<int> ans;
        for(int i=0; i < n; i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
