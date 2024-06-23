class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> histo(m, 0);
        int base = 0, length = 0;
        
        int first = INT_MAX, last = -1;
        int a = INT_MAX, b = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    first = min(first, i);
                    last = max(last, i);
                    a = min(a, j);
                    b = max(b, j);
                }
            }
        }
        length = last-first+1;
        base = b-a+1;
        
        return length*base;
    }
};
