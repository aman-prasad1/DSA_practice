class Solution {
public:
    int solve(int r1 , int c1 , int r2 , int n , vector<vector<int>> &grid, vector<vector<vector<int>>>& dp){
        int c2=r1+c1-r2;
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        
        if(dp[r1][c1][r2]!=-1){
            return dp[r1][c1][r2];
        }
        
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        
        int ans=grid[r1][c1];
        
        if(r1!=r2){
            ans += grid[r2][c2];
        }
        
        int temp= max(solve(r1+1 , c1 , r2+1 , n , grid, dp) , solve(r1 , c1+1 , r2 , n , grid, dp));
        temp = max(temp , solve(r1+1 , c1 , r2 , n, grid, dp));
        temp = max(temp , solve(r1 , c1+1 , r2+1 , n , grid, dp));
        
        ans+=temp;
        
        return dp[r1][c1][r2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(51, -1)));
        int n=grid.size();
        return max(0 , solve(0,0,0,n , grid, dp));
    }
};