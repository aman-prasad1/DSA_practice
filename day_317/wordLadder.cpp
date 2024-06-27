class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        
        wordList.insert(wordList.begin(), beginWord);
        int n = wordList.size();
        int endWordIndex = -1;

        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord)
                endWordIndex = i;
            for (int j = i + 1; j < n; j++) {
                int matched = 0;
                for (int k = 0; k < beginWord.size(); k++) {
                    if (wordList[i][k] == wordList[j][k])
                        matched++;
                }
                if (matched == beginWord.size() - 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        if (endWordIndex == -1)
            return 0;
        vector<int> distance(n, INT_MAX);
        distance[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (distance[node] + 1 < distance[neighbor]) {
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return distance[endWordIndex] == INT_MAX ? 0: distance[endWordIndex] + 1;
    }
};
