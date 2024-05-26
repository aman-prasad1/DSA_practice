class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        unordered_map<int,int> mp;
        
        for(int i : nums2) mp[i*k]++;
        for(int n : nums1){
            int temp = sqrt(n);
            for(int i=1; i<=temp; i++){
                if(n%i != 0) continue;
                ans += mp[i];
                if(i*i != n) ans += mp[n/i];
            }
        }
        return ans;
    }
};
