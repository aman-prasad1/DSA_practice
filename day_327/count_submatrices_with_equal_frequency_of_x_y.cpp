class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        vector<vector<int>> x(row+1, vector<int>(col+1, 0));
        vector<vector<int>> y(row+1, vector<int>(col+1, 0));

        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                x[i][j] = x[i-1][j] + x[i][j-1] - x[i-1][j-1] + (grid[i-1][j-1] == 'X'? 1:0);
                y[i][j] = y[i-1][j] + y[i][j-1] - y[i-1][j-1] + (grid[i-1][j-1] == 'Y'? 1:0);

            }
        }


        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                if(x[i][j] == y[i][j] && x[i][j] != 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};
