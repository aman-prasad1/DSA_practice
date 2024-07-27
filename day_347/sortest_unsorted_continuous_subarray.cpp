class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        // APPROACH 1
        // vector<int> temp(nums.begin(), nums.end());
        // sort(nums.begin(), nums.end());

        // int i = 0, j = nums.size()-1;
        // for(; i<nums.size(); i++){
        //     if(temp[i] != nums[i]){
        //         break;
        //     }
        // }
        // for(; j>=0; j--){
        //     if(temp[j] != nums[j]){
        //         break;
        //     }
        // }

        // if(i > j) return 0;
        // return j-i+1;


        // APPROACH 2

        int s = 0, e = 0, maxi = INT_MIN, mini = INT_MAX;

        for(int i=nums.size()-1; i>=0; i--){
            mini = min(mini, nums[i]);
            if(nums[i] > mini) s = i;
        }
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            if(nums[i] < maxi) e = i;
        }

        if(s >= e) return 0;
        return e-s+1;
    }
};
