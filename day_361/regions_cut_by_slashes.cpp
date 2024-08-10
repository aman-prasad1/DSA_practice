class Solution {
    int n1, m1, n2, m2;
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int r, int c){
        if(r < 0 || c < 0 || r >= n2 || c >= m2 || matrix[r][c] != 0 || visited[r][c]){
            return;
        }

        visited[r][c] = true;
        vector<vector<int>> neighbour = {{r+1, c}, {r, c+1}, {r-1, c}, {r, c-1}};

        for(auto nbr : neighbour){
            dfs(matrix, visited, nbr[0], nbr[1]);
        }
        
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        n1 = grid.size(), m1 = grid[0].size();
        n2 = n1 * 3, m2 = m1 * 3;

        vector<vector<int>> matrix(n2, vector<int>(m2, 0));

        for(int i=0; i<n1; i++){
            for(int j=0; j<m1; j++){
                int r = i*3, c = j*3;
                if(grid[i][j] == '/'){
                    matrix[r][c+2] = 1;
                    matrix[r+1][c+1] = 1;
                    matrix[r+2][c] = 1;
                }
                else if(grid[i][j] == '\\'){
                    matrix[r][c] = 1;
                    matrix[r+1][c+1] = 1;
                    matrix[r+2][c+2] = 1;
                }
            }
        }

        vector<vector<bool>> visited(n2, vector<bool>(m2, 0));
        int ans = 0;
        for(int r=0; r<n2; r++){
            for(int c=0; c<m2; c++){
                if(matrix[r][c] == 0 && !visited[r][c]){
                    dfs(matrix, visited, r, c);
                    ans++;
                }
            }
        }
        return ans;
    }
};
