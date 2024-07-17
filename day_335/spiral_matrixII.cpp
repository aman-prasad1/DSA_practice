class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n, 0));

        int row_start = 0, row_end = n-1;
        int col_start = 0, col_end = n-1;

        int val = 1;
        while(val <= n*n){
            // from col_start to col_end
            for(int j=col_start; j <= col_end; j++){
                grid[row_start][j] = val++;
            }
            row_start++;

            // from row_start to row_end
            for(int i=row_start; i <= row_end; i++){
                grid[i][col_end] = val++;
            }
            col_end--;

            // from col_end to col_start
            for(int j=col_end; j >= col_start; j--){
                grid[row_end][j] = val++;
            }
            row_end--;

            // from row_end to row_start
            for(int i=row_end; i >= row_start; i--){
                grid[i][col_start] = val++;
            }
            col_start++;
        }

        return grid;
    }
};
