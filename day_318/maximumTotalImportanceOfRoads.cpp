class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<long long> adj(n, 0);
        for(auto road : roads){
            adj[road[0]]++;
            adj[road[1]]++;
        }
        sort(adj.begin(), adj.end(), greater<int>());

        long long ans = 0;
        for(long long temp : adj){
            ans += temp*n;
            n--;
        }
        return ans;
    }
};
