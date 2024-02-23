class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> prevMoney(n, INT_MAX);
        prevMoney[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [node, cost] = q.front();
                q.pop();

                if (!adj.count(node)) continue;

                for (auto& [neighbour, price] : adj[node]) {
                    if (price + cost >= prevMoney[neighbour]) continue;
                    prevMoney[neighbour] = price + cost;
                    q.push({neighbour, prevMoney[neighbour]});
                }
            }
            stops++;
        }
        return prevMoney[dst] == INT_MAX ? -1 : prevMoney[dst];
    }
};

