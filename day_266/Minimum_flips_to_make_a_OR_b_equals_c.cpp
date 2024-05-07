class Solution {
public:
    int minFlips(int a, int b, int c) {
        int AorB = a | b;
        int AandB = a & b;
        int ans = 0;
        while(AorB || c){
            bool orbit = AorB & 1;
            AorB >>= 1;
            bool andbit = AandB & 1;
            AandB >>= 1;
            bool bitc = c & 1;
            c >>= 1;

            if(orbit != bitc){
                if(andbit){
                    ans++;
                }
                ans++;
            }
        }
        return ans;
    }
};
