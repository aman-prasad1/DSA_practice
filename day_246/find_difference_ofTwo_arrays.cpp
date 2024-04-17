class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        // mp[i] == 1 means it only present in nums1
        // mp[i] == 2 means it only present in nums2   
        // mp[i] == 3 means it is present in both array
        for(int i : nums1){
            mp[i] = 1;
        }
        for(int i : nums2){
            if(mp[i] == 1 || mp[i] == 3) mp[i] = 3;
            else mp[i] = 2;
        }

        vector<vector<int>> ans(2);
        for(int i : nums1){
            if(mp[i] == 1){
                ans[0].push_back(i);
                mp.erase(i);
            } 
        }
        for(int i : nums2){
            if(mp[i] == 2){
                ans[1].push_back(i);
                mp.erase(i);
            }
        }

        return ans;
    }
};