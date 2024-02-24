class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        vector<pair<int,int>> adj[n];
        for (auto i : meetings) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vector<int> vis(n, 0);

        while (!pq.empty()) {
            auto it = pq.top();
            int time=it.first; 
            int person=it.second;
            pq.pop();

            if (vis[person]) {
                continue;
            }
            vis[person] = true;
            for (auto it : adj[person]) {
                if (!vis[it.first] && it.second >= time) {
                    pq.push({it.second, it.first});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};