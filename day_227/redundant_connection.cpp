class Solution {
    int parFind(int n, vector<int>& par){
        int p = par[n];
        while(p != par[p]){
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    bool check(int n1, int n2, vector<int>& par, vector<int>& rank){
        int p1 = parFind(n1, par);
        int p2 = parFind(n2, par);

        if(p1 == p2) return false;

        if(rank[p1] > rank[p2]){
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        else{
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> rank(edges.size() + 1, 1);
        vector<int> par(edges.size() + 1);
        for(int i=0; i<=edges.size(); i++){
            par[i] = i;
        }

        for(auto i : edges){
            if(!check(i[0], i[1], par, rank)){
                return i;
            }
        }
        return {-1,-1};
    }
};