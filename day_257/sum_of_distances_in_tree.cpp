class Solution {
private:
    unordered_map<int, vector<int>> mp;

    void dfs(int node, int parent, vector<int>& cnt, vector<int>& ans) {
        for (int child : mp[node]) {
            if (child != parent) {
                dfs(child, node, cnt, ans);
                cnt[node] += cnt[child];
                ans[node] += ans[child] + cnt[child];
            }
        }
    }

    void dfs2(int node, int parent, vector<int>& cnt, vector<int>& ans) {
        for (int child : mp[node]) {
            if (child != parent) {
                ans[child] = ans[node] - cnt[child] + (cnt.size() - cnt[child]);
                dfs2(child, node, cnt, ans);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> cnt(n, 1);
        vector<int> ans(n, 0);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        dfs(0, -1, cnt, ans);
        dfs2(0, -1, cnt, ans);

        return ans;
    }
};
