class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> dist(n, INT_MAX);
        vector<int> ans;

        dist[0] = 0;
        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1);
            dist[i+1] = dist[i]+1;
        }

        queue<int> q;
        for(auto query : queries){
            int u = query[0], v = query[1];
            adj[u].push_back(v);
            if(dist[v] > dist[u]+1){
                dist[v] = dist[u]+1;
            }
            q.push(v);
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(int nbr : adj[front]){
                    if(dist[nbr] > dist[front]+1){
                        dist[nbr] = dist[front]+1;
                        q.push(nbr);
                    }
                }
            }
            ans.push_back(dist[n-1]);
        }

        return ans;
    }
};


// simple bfs approach

// class Solution {
//     int solve(int n, vector<vector<int>>& adj){
//         queue<int> q;
//         int path = 0;
//         q.push(0);
//         q.push(-1);

//         vector<bool> visited(n, 0);
//         while(!q.empty()){
//             int front = q.front();
//             q.pop();


//             if(front == -1){
//                 if(!q.empty()){
//                     q.push(-1);
//                     path++;
//                 }
//                 continue;
//             }
//             visited[front] = true;

//             if(front == n-1) return path;

//             for(int nbr : adj[front]){
//                 if(!visited[nbr]) q.push(nbr);
//             }
//         }

//         return -1;
//     }
// public:
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         vector<vector<int>> adj(n);
//         for(int i=0; i<n-1; i++){
//             adj[i].push_back(i+1);
//         }

//         vector<int> ans;
//         for(int i=0; i<queries.size(); i++){
//             adj[queries[i][0]].push_back(queries[i][1]);
//             ans.push_back(solve(n, adj));
//         }

//         return ans;
//     }
// };
