class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;

        int prev3 = 0, prev2 = 1, prev1 = 1;
        int ans = 1;
        for(int i=3; i<=n; i++){
            ans = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;;
            prev1 = ans;
        }
        return ans;
    }
};
