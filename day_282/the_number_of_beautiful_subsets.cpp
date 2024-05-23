class Solution {
    int ans = 0;
    vector<int> arr;

    void solve(int ind, vector<int>& nums, int k){
        if(ind >= nums.size()){
            ans++;
            return;
        }

        // include
        bool valid = true;
        for(int i=0; i<arr.size(); i++){
            if(abs(arr[i] - nums[ind]) == k){
                valid = false;
                break;
            }
        }
        if(valid){
            arr.push_back(nums[ind]);
            solve(ind+1, nums, k);
            arr.pop_back();
        }
        
        // exclude
        solve(ind+1, nums, k);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        solve(0, nums, k);
        return ans-1;
    }
};
