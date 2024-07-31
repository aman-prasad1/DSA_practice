class Solution {
    bool solve(int ind, int k, vector<int>& stones, vector<map<int,int>>& dp){
        if(ind == stones.size()-1) return true;
        if(dp[ind].find(k) != dp[ind].end()) return dp[ind][k];

        bool isPossible = false;
        for(int i=ind; i<stones.size()-1 && stones[i] + k + 1 >= stones[i+1]; i++){
            for(int newk = k-1; newk <= k+1; newk++){
                if(stones[ind] + newk == stones[i+1]){
                    isPossible = isPossible || solve(i+1, newk, stones, dp);
                    if(isPossible) return dp[ind][k] = true;
                }
            }
        }
        return dp[ind][k] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        vector<map<int,int>> dp(stones.size());
        return solve(0, 0, stones, dp);
    }
};
