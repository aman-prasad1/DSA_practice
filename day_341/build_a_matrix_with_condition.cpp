class Solution {
public:
    vector<vector<int>> buildGraph(int k, vector<vector<int>>&graph){
        vector<vector<int>> adj(k+1);
        for(auto it: graph){
            adj[it[0]].push_back(it[1]);
        }
        return adj;
    }

    vector<int> toposort(int k, vector<vector<int>>&adj){
        vector<int> topo;
        vector<int> indegree(k+1,0);

        for(int u=1;u<=k;u++){
            for(int v: adj[u]){
                indegree[v]++;
            }
        }

        queue<int> q;
        vector<bool> vis(k+1,false);

        for(int u=1; u<=k; u++){
            if(indegree[u] == 0)
                q.push(u);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(int v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        for(int u=1;u<=k;u++){
            if(indegree[u] != 0){
                return {};
            }
        }

        return topo;
    }

    void fillTopo(int k, vector<int>&topo){
        unordered_map<int,bool>vis;

        for(int u: topo)
            vis[u] = true;

        for(int u=1;u<=k;u++){
            if(!vis[u]){
                topo.push_back(u);
            }
        }
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> row = buildGraph(k,rowConditions);
        vector<vector<int>> col = buildGraph(k,colConditions); 

        vector<int> rowTopo = toposort(k, row);
        vector<int> colTopo = toposort(k, col); 

        if(rowTopo.empty() || colTopo.empty())
            return {};

        vector<vector<int>>mat(k,vector<int>(k,0));

        fillTopo(k,rowTopo);
        fillTopo(k,colTopo);

        unordered_map<int,int>colInd;
        for(int j=0;j<k;j++){
            colInd[colTopo[j]] = j;
        }  

        for(int i=0;i<k;i++){
            mat[i][colInd[rowTopo[i]]] = rowTopo[i];
        }

        return mat;
    }
};