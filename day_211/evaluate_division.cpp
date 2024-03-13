class Solution {
    unordered_map<string,list<pair<string,double>>> adj;
    unordered_map<string,bool> visited;
    double solve(string src, string des, double res){
        if(adj[src].size() == 0) return -1.0;
        
        if(src == des){
            return res;
        }
        if(visited[src]){
            return -1.0;
        }

        visited[src] = true;

        double val = 0.0;
        for(auto nbr : adj[src]){
            if(visited[nbr.first]) continue;
            val = solve(nbr.first, des,res * nbr.second);
            if(val > 0){
                break;
            }
        }
        visited[src] = false;
        return (val != 0.0)? val : -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        for(int i=0; i<values.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            adj[a].push_back(make_pair(b,val));
            adj[b].push_back(make_pair(a, 1.0/val));
        }

        vector<double> ans;
        for(int i=0; i<queries.size(); i++){
            double res = solve(queries[i][0], queries[i][1], 1.0);
            ans.push_back(res);
            cout << res << " ";
        }
        return ans;
    }
};