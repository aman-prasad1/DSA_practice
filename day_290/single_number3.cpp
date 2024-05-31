class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2);
        int xor_num = 0;
        for(int num : nums){
            xor_num ^= num;
        }

        int diff = 1;
        while(!(diff & xor_num)){
            diff <<= 1;
        }

        int a = 0, b = 0;
        for(int num : nums){
            if(num & diff) a ^= num;
            else b ^= num;
        }
        ans[0] = a;
        ans[1] = b;
        return ans;
    }
};
