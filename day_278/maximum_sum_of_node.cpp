class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> delta(nums.size());
        for(int i=0; i<nums.size(); i++){
            delta[i] = (nums[i] ^ k) - nums[i];
        }
        sort(delta.begin(), delta.end(), greater<int>());

        long long sum = 0;
        for(int i : nums){
            sum += i;
        }

        for(int i=0; i<nums.size(); i+=2){
            if(i == nums.size()-1) break;

            int temp = delta[i] + delta[i+1];
            if(temp <= 0) break;
            else sum += temp;
        }
        return sum;
    }
};
