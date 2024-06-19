class Solution { 
    bool isPossible(int mid, vector<int>& bloomDay, int m, int k){
        // this function returns m number of bouquets is possible on day mid
        int cnt = 0, bouquet = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else
                cnt = 0;

            if(cnt == k){
                bouquet++;
                cnt = 0;
            }
        }
        return bouquet >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int n = bloomDay.size();
        if((long)m * k > n) return -1;

        int s = 1, e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(s <= e){
            int mid = s+(e-s)/2;
            if(isPossible(mid, bloomDay, m, k)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
