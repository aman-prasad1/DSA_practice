class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;

        for(int i=5; n/i > 0; i *= 5){
            ans += n/i;
        }
        return ans;
    }
};
