class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>> pq;

        int cnt = 0;
        int i = 0, j = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(cnt < k){
                    pq.push({((double)arr[i]/(double)arr[j]), {arr[i],arr[j]}});
                    cnt++;
                }
                else{
                    if(((double)arr[i]/(double)arr[j]) < pq.top().first){
                        pq.pop();
                        pq.push({((double)arr[i]/(double)arr[j]), {arr[i],arr[j]}});
                    }
                }
            }
        }

        return {pq.top().second.first, pq.top().second.second};
    }
};
