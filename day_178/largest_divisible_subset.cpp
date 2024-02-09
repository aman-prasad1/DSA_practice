class Solution {
public:
    vector<int> result;
    void helper(int i, int n, vector<int> &nums, vector<int> &temp, vector<int> &dp){
        if(i==n){
            if(temp.size()>result.size())
                result=temp;
        return;
        }
        if(temp.size()==0){
            temp.push_back(nums[i]);
            helper(i+1,n,nums,temp,dp);
            temp.pop_back();
        }
        else if((int)temp.size()>dp[i] and nums[i]%temp.back()==0){
            dp[i]=temp.size();
            temp.push_back(nums[i]);
            helper(i+1,n,nums,temp,dp);
            temp.pop_back();
        }
    helper(i+1,n,nums,temp,dp);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp, dp(n+1,-1);
        sort(nums.begin(),nums.end());
        helper(0,n,nums,temp,dp);
    return result;
    }
};