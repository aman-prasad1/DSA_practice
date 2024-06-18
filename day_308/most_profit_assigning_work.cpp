class Solution {
public:
    // int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    //     int n = worker.size();
    //     priority_queue<pair<int,int>> pq;
    //     sort(worker.begin(), worker.end());

    //     for(int i=0; i<profit.size(); i++){
    //         if(difficulty[i] <= worker[n-1]){
    //             pq.push({profit[i],difficulty[i]});
    //         }
    //     }

    //     int ans = 0;
    //     for(int i=n-1; i>=0 && !pq.empty(); ){
    //         auto top = pq.top();
    //         if(worker[i] >= top.second){
    //             ans += top.first;
    //             i--;
    //         }
    //         else{
    //             pq.pop();
    //         }
    //     }
    //     return ans;

    // }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        vector<pair<int,int>> v;

        sort(worker.begin(), worker.end());

        for(int i=0; i<profit.size(); i++){
            if(difficulty[i] <= worker[n-1]){
                v.push_back({profit[i],difficulty[i]});
            }
        }
        sort(v.begin(), v.end());

        int ans = 0;
        int j = v.size()-1;
        for(int i=n-1; i>=0 && j>=0; ){
            if(worker[i] >= v[j].second){
                ans += v[j].first;
                i--;
            }
            else{
                j--;
            }
        }
        return ans;

    }
};
