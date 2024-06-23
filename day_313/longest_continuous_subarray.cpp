class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        int i=0, j=0, ans = 0;

        multiset<int> s;
        while(j<n){
            s.insert(nums[j]);
            int diff = *s.rbegin()-*s.begin();
            while(i<j && diff > limit){
                auto it = s.find(nums[i]);
                s.erase(it);
                i++;
                diff = *s.rbegin()-*s.begin();
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
