class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n = customers.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            if(grumpy[i] == 0){
                ans += customers[i];
                customers[i] = 0;
            }
        }

        int window_sum = 0;
        int max_window_sum = 0;
        int i=0, j=0;
        while(j < n){
            window_sum += customers[j];
            if(j-i == minutes){
                window_sum -= customers[i++];
            }
            j++;
            max_window_sum = max(max_window_sum, window_sum);
        }
        return ans + max_window_sum;

    }
};
