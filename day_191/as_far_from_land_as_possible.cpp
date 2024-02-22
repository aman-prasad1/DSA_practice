class Solution{
public:
    int maxDistance(vector<vector<int>> &grid){
        int i, j, m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                if (grid[i][j]){
                    q.push({i, j});
                    grid[i][j] = 2;
                }
            }
        }
        int x = 0;
        vector<int> v;
        while (!q.empty()){
            int n1 = q.size();
            x++;
            while (n1--){
                v = q.front();
                q.pop();
                if (v[0] - 1 >= 0 && grid[v[0] - 1][v[1]] == 0){
                    q.push({v[0] - 1, v[1]});
                    grid[v[0] - 1][v[1]] = 2;
                }
                if (v[0] + 1 < m && grid[v[0] + 1][v[1]] == 0){
                    q.push({v[0] + 1, v[1]});
                    grid[v[0] + 1][v[1]] = 2;
                }
                if (v[1] - 1 >= 0 && grid[v[0]][v[1] - 1] == 0){
                    q.push({v[0], v[1] - 1});
                    grid[v[0]][v[1] - 1] = 2;
                }
                if (v[1] + 1 < n && grid[v[0]][v[1] + 1] == 0){
                    q.push({v[0], v[1] + 1});
                    grid[v[0]][v[1] + 1] = 2;
                }
            }
        }
        return x - 1 == 0? -1 : x-1;
    }
};