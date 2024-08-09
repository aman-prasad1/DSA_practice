/* 
  check every possible 3x3 matrix were magic square or not
*/

class Solution {
    int n , m;
    bool isMagic(vector<vector<int>>& grid, int x, int y){
        vector<int> row_sum(3, 0);
        vector<int> col_sum(3, 0);
        set<int> s = {1,2,3,4,5,6,7,8,9};

        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                row_sum[i-x] += grid[i][j];
                col_sum[j-y] += grid[i][j];
                s.erase(grid[i][j]);
            }
        }

        if( row_sum[0] != row_sum[1] ||
            row_sum[0] != row_sum[2] ||
            row_sum[0] != col_sum[0] ||
            row_sum[0] != col_sum[1] ||
            row_sum[0] != col_sum[2]) return false;

        if(grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2] != 15) return false;
        if(grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y] != 15) return false;
        return s.empty();
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                if(isMagic(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};
