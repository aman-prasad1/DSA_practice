// APPROACH 1

// class Solution {
// public:
//     vector<vector<int>> spiralMatrixIII(int row, int col, int rStart, int cStart) {
//         vector<vector<int>> grid;
//         int grid_max_size = row * col;

//         int row_start = rStart, row_end = rStart;
//         int col_start = cStart, col_end = cStart+1;
//         bool flag = false;
//         while(grid.size() < grid_max_size){

//             for(int c=(flag)? col_start+1 : col_start; c <= col_end; c++){
//                 if(row_start >=0 && c >= 0 && c < col){
//                     grid.push_back({row_start, c});
//                 }
//             }
//             row_end++;
//             flag = true;

//             for(int r=row_start+1; r <= row_end; r++){
//                 if(col_end < col && r >= 0 && r < row){
//                     grid.push_back({r, col_end});
//                 }
//             }
//             col_start--;

//             for(int c=col_end-1; c >= col_start; c--){
//                 if(row_end < row && c >= 0 && c < col){
//                     grid.push_back({row_end, c});
//                 }
//             }
//             row_start--;

//             for(int r=row_end-1; r >= row_start; r--){
//                 if(col_start >= 0 && r >= 0 && r < row){
//                     grid.push_back({r, col_start});
//                 }
//             }
//             col_end++;
//         }

//         return grid;
//     }
// };

// APPROACH 2

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> grid;
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int r = rStart, c = cStart, steps = 1, i = 0;
        int grid_max_size = rows * cols;

        while(grid.size() < grid_max_size){
            for(int x=0; x < 2; x++){
                int dr = directions[i][0], dc = directions[i][1];
                for(int y=0; y < steps; y++){
                    if(r >= 0 && r < rows && c >= 0 && c < cols){
                        grid.push_back({r, c});
                    }
                    r += dr, c += dc;
                }
                i = (i + 1) % 4;
            }
            steps++;
        }

        return grid;
    }
};

