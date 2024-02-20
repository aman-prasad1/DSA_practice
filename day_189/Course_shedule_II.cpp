class Solution {
    bool dfs(int n, unordered_map<int, list<int>> &adj, vector<bool> &visited, int node, vector<int>& ans){
        if(visited[node]){
            return false;
        }
        if(adj[node].empty()){
            return true;
        }
        
        visited[node] = 1;
        for(auto nbr : adj[node]){
            bool check = dfs(n, adj, visited, nbr, ans);
            if(!check){
                return false;
            }
        }
        ans.push_back(node);
        visited[node] = 0;
        adj[node].clear();
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for(auto i : prerequisites){
            int first = i[0];
            int second = i[1];
            
            adj[first].push_back(second);
        }
        
        vector<bool> visited(numCourses, 0);
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(adj[i].empty()){
                ans.push_back(i);
            }
        }
        bool check = false;
        for(int node = 0; node < numCourses; node++){
            check = dfs(numCourses, adj, visited, node, ans);
            if(!check)
                return {};
        }
        return ans;
    }
};