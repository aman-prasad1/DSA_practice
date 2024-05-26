#define mod 1000000007
class Solution {
    // int solve(int ind, int a, int l, int n, vector<vector<vector<int>>>& dp){
    //     if(ind >= n) return 1;
    //     if(dp[ind][a][l] != -1) return dp[ind][a][l];

    //     int present = 0, late = 0, absent = 0;
    //     // present
    //     present = solve(ind+1, a, 0, n, dp);

    //     // late
    //     if(l < 2) late = solve(ind+1, a, l+1, n, dp);

    //     // absent
    //     if(a == 0) absent = solve(ind+1, a+1, 0, n, dp);

    //     return dp[ind][a][l] = (((present + late) % mod) + absent)% mod;
    // }
    int solve(int n){
        int dp[100001][2][3];
        for(int a=0; a<2; a++){
            for(int l=0; l<3; l++){
                dp[n][a][l] = 1;
            }
        }
        int ans = 0;
        for(int ind=n-1; ind>=0; ind--){
            for(int a=0; a<=1; a++){
                for(int l=0; l<=2; l++){
                    long long ans = dp[ind+1][a][0];
                    ans += (l<2)? dp[ind+1][a][l+1] : 0;
                    ans += (a==0)?dp[ind+1][a+1][0] : 0;
                    dp[ind][a][l] = ans % mod;
                }
            }
        }
        return dp[0][0][0];
    }
public:
    int checkRecord(int n) {
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(0, 0, 0, n, dp);

        return solve(n);
    }
};
