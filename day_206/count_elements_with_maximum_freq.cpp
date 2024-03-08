class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        int cnt = 0;
        int val = nums[0];

        for(auto i : mp){
            if(i.second > mp[val]){
                cnt = i.second;
                val = i.first;
            }
            else if(i.second == mp[val]){
                cnt += i.second;
            }   
        }
        return cnt;
    }
};