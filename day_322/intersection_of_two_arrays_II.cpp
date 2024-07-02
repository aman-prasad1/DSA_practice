class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            mp[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            if(mp[nums2[i]] >= 1){
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};
