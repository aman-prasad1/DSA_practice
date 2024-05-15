class Solution {
public:
    vector<int> row = {0,0,-1,1};
    vector<int> col = {-1,1,0,0};

    void bfs(vector<vector<int>>& grid,vector<vector<int>>& dist,int n) {
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j]) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int x = t.first, y = t.second;
            int s = dist[x][y];

            for(int i =0; i < 4; i++){
                int newX = x + row[i];
                int newY = y + col[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && dist[newX][newY] > 1 + s) { 
                    dist[newX][newY] = 1 + s;
                    q.push({newX, newY});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return 0;

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        bfs(grid, dist, n); // calculating the minimum distance of a cell from the thief
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({dist[0][0], {0,0}});

        while(!pq.empty()){
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if(temp.first == n - 1 && temp.second == n - 1) return safe;
            vis[temp.first][temp.second] = true;

            for(int i = 0; i < 4; i++) {
                int newX = temp.first + row[i];
                int newY = temp.second + col[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]){
                    int s = min(safe, dist[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }

        return -1;
    }
};
