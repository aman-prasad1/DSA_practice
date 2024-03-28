class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp; // it contains the count of elements in the sub array

        int i = 0, j = 0, maxi = 0; // i and j the sub array from i to j. And maxi is the max size of the sub array
        
        while(i < n && j < n){
            while(j < n && mp[nums[j]] < k){ // j will run till the freq of elements inside the window is less than k
                mp[nums[j]]++;
                j++;
            }

            // after getting a good window caluuclate the length and save it in them maxi if greater than maxi
            int len = j-i;
            maxi = max(maxi, len);

            // now increment the i index till the count of element in j index is less than k and also decrement the count of element which excluded from window 
            while(i < j && j < n && nums[i] != nums[j]){
                mp[nums[i]]--;
                i++;
            }
            mp[nums[i]]--;
            i++;
        }
        return maxi;
    }
};