class Solution {
    void dfs(unordered_map<int,vector<int>>& adj, int parent, int curr, vector<vector<int>>& ans, vector<bool>& visited){
        visited[curr] = true;
        for(int nbr : adj[curr]){
            if(!visited[nbr]){
                ans[nbr].push_back(parent);
                dfs(adj, parent, nbr, ans, visited);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> ans(n);

        for(int i=0; i<n; i++){
            vector<bool> visited(n, false);
            dfs(adj, i, i, ans, visited);
        }

        for(int i=0; i<n; i++){
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
