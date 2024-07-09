class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double watingTime = customers[0][1];
        int finished = customers[0][0] + customers[0][1];

        for (int i = 1; i < n; i++) {
            int arrive = customers[i][0];
            int time = customers[i][1];

            int start = max(arrive, finished);
            finished = start + time;
            watingTime += finished - arrive;
        }

        return watingTime / n;
    }
};
