class neighborSum {
    vector<vector<int>> grid;
    int n;
public:
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        this->grid = grid;
    }
    
    int adjacentSum(int value) {
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == value){
                    int sum = 0;
                    sum += (i-1 >= 0)? grid[i-1][j] : 0;
                    sum += (i+1 < n)?  grid[i+1][j] : 0;
                    sum += (j-1 >= 0)? grid[i][j-1] : 0;
                    sum += (j+1 < n)?  grid[i][j+1] : 0;
                    return sum;
                }
            }
        }
        return -1;
    }
    
    int diagonalSum(int value) {
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == value){
                    int sum = 0;
                    sum += (i-1 >= 0 && j-1 >= 0)? grid[i-1][j-1] : 0;
                    sum += (i+1 < n && j-1 >= 0)?  grid[i+1][j-1] : 0;
                    sum += (i+1 < n && j+1 < n)?   grid[i+1][j+1] : 0;
                    sum += (i-1 >= 0 && j+1 < n)?  grid[i-1][j+1] : 0;
                    return sum;
                }
            }
        }
        return -1;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
