class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(nums.size(), 0);
        for(int i=1; i<nums.size(); i++){
            if((nums[i] + nums[i-1])%2 == 0) res[i] = 1;
            res[i] += res[i-1];
        }

        vector<bool> ans;
        for(auto i : queries){
            int from = i[0];
            int to = i[1];

            if(res[from] != res[to]) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};
