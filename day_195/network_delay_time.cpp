class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto time : times){
            adj[time[0]].push_back(make_pair(time[1], time[2]));
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<bool> visited(n+1, false);
        q.push(make_pair(0,k));
        int i = 0; // to check time when node recive signal
        int cnt = 1;

        while(!q.empty()){
            auto [time, node] = q.top();
            if(visited[node]){
                q.pop();
                continue;
            }
            if(time <= i){
                visited[node] = true;
                q.pop();
                
                for(auto& nbr : adj[node]){
                    if(!visited[nbr.first]){
                        q.push(make_pair(nbr.second+time, nbr.first));
                        cnt++;
                    }
                }
            }
            else{
                i++;
            }
        }
        for(int ind=1; ind<=n; ind++){
            if(!visited[ind]){
                return -1;
            }
        }
        return i;
    }
};