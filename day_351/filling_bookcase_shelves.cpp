class Solution {
    int solveMem(int ind, vector<vector<int>>& books, int shelfWidth, vector<int>& dp){
        if(ind >= books.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        int curr_width = shelfWidth;
        int max_height = 0;
        int ans = INT_MAX;
        for(int i=ind; i<books.size(); i++){
            int w = books[i][0], h = books[i][1];
            if(curr_width < w) break;
            
            curr_width -= w;
            max_height = max(max_height, h);
            ans = min(ans, solveMem(i+1, books, shelfWidth, dp) + max_height);
        }

        return dp[ind] = ans;
    }
    int solveIterative(vector<vector<int>>& books, int shelfWidth){
        int n = books.size();

        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int ind=n-1; ind>=0; ind--){
            int curr_width = shelfWidth;
            int max_height = 0;
            int ans = INT_MAX;
            for(int i=ind; i<books.size(); i++){
                int w = books[i][0], h = books[i][1];
                if(curr_width < w) break;
                
                curr_width -= w;
                max_height = max(max_height, h);
                ans = min(ans, dp[i+1] + max_height);
            }
            dp[ind] = ans;
        }
        return dp[0];
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // Recursive + memoization
        // vector<int> dp(books.size(), -1);
        // return solveMem(0, books, shelfWidth, dp);


        // Itretive method
        return solveIterative(books, shelfWidth);

    }
};
