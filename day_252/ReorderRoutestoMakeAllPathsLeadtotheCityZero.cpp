class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> undirected;
        unordered_map<int, vector<int>> directed;
        vector<bool> visited(n, false);

        for(int i=0; i<connections.size(); i++){
            int src = connections[i][0];
            int dst = connections[i][1];
            undirected[src].push_back(dst);
            undirected[dst].push_back(src);

            directed[src].push_back(dst);
        }

        int ans = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int front = q.front();
            q.pop();
            visited[front] = true;
            for(int nbr : undirected[front]){
                if(visited[nbr]) continue;
                cout << front << " " << nbr << endl;
                if(count(directed[nbr].begin(), directed[nbr].end(), front) == 0){
                    ans++;
                    cout << count(directed[nbr].begin(), directed[nbr].end(), front) << "->" << ans << endl;
                }
                q.push(nbr);
            }
        }

        return ans;
    }
};
