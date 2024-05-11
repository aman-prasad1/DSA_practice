class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> pairs;
        for(int i=0; i<quality.size(); i++){
            double ratio = (double) wage[i] / (double) quality[i];
            pairs.push_back({ratio, quality[i]});
        }
        sort(pairs.begin(), pairs.end());

        priority_queue<int> pq;
        int total_quality = 0;
        double ans = INT_MAX;

        for(auto [ratio, q] : pairs){
            pq.push(q);
            total_quality += q;

            if(pq.size() > k){
                int top = pq.top();
                pq.pop();
                total_quality -= top;
            }

            if(pq.size() == k){
                cout << ans << endl;
                ans = min(ans, (double) total_quality * ratio);
            }
        }

        return ans;
    }
};
