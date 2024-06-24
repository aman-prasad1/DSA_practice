class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        int curr_flip = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i-k >= 0 && nums[i-k] == 2){
                curr_flip--;
            }
            if((curr_flip+nums[i])%2 == 0){
                if(i+k > n) return -1;
                nums[i] = 2;
                curr_flip++;
                ans++;
            }
        }
        return ans;
    }
};
