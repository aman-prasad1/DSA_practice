class Solution {
    int n, m;

    int solve(vector<vector<int>>& grid, int i, int j){
        if(i >= n || j >= m) return 0;

        int gold = grid[i][j];
        grid[i][j] = 0; // marking it as visited

        int left = 0, right = 0, up = 0, down = 0;

        // left
        if(j-1 >= 0 && grid[i][j-1]){
            left = solve(grid, i, j-1);
        }
        // right
        if(j+1 < m && grid[i][j+1]){
            right = solve(grid, i, j+1);
        }
        // down
        if(i+1 < n && grid[i+1][j]){
            up = solve(grid, i+1, j);
        }
        //up 
        if(i-1 >= 0 && grid[i-1][j]){
            down = solve(grid, i-1, j);
        }

        grid[i][j] = gold;
        return gold + max(left, max(right, max(up, down)));
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]) 
                    ans = max(ans, solve(grid, i, j));
            }
        }
        return ans;
    }
};
