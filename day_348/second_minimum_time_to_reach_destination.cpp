class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        vector<vector<int>> adj(n+1);
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        int totalTime = 0, pathCount = 0;
        queue<int> q;
        vector<pair<int,int>> visited(n+1, {0,0}); // {times_visited, time}
        q.push(1), q.push(-1);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            if(front == -1){
                if(q.empty()) break;
                q.push(-1);
                if((totalTime/change) % 2 != 0){
                    totalTime += change - (totalTime % change);
                }
                totalTime += time;
                continue;
            }

            if(front == n){
                pathCount++;
                if(pathCount == 2){
                    break;
                }
            }

            for(int nbr : adj[front]){
                if(visited[nbr].first ==0 || (visited[nbr].first == 1 && visited[nbr].second != totalTime)){
                    q.push(nbr);
                    visited[nbr].second = totalTime;
                    visited[nbr].first++;
                }
            }
        }

        return totalTime;
    }
};
