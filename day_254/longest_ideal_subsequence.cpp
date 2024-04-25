class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(27, 0);

        for(char ch : s){
            int maxi = 1;
            for(int i='a'; i<='z'; i++){
                if(abs(ch - i) <= k){
                    maxi = max(maxi, 1+dp[i-'a']);
                }
            }
            dp[ch - 'a'] = max(dp[ch-'a'], maxi); 
        }

        int ans = 0;
        for(int i=0; i<=26; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
