class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorOfElements = nums[0];

        for(int i=1; i<nums.size(); i++){
            xorOfElements ^= nums[i];
        }

        int ans = 0;
        while(xorOfElements || k){
            int bit1 = xorOfElements & 1;
            int bit2 = k & 1;

            xorOfElements >>= 1;
            k >>= 1;

            if(bit1 != bit2) ans++;
        }
        return ans;
    }
};
