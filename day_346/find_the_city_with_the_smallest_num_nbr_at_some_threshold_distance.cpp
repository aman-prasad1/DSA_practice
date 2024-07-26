class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++){
            distance[i][i] = 0;
        }
        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            distance[u][v] = distance[v][u] = w;
        }
        for(int k = 0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
                }
            }
        }

        int mini = n, city = -1;
        for(int i=0; i<n; i++){
            int cnt = -1;
            for(int j=0; j<n; j++){
                if(distance[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= mini){
                mini = cnt;
                city = i;
            }
        }

        return city;
    }
};
