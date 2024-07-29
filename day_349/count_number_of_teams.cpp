class Solution {
public:
    int numTeams(vector<int>& rating) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int n = rating.size();
        int ans = 0;
        
        for(int m=1; m < n-1; m++){
            int left_smaller = 0, right_smaller = 0, left_larger = 0, right_larger = 0;
            for(int i=0; i<m; i++){
                if(rating[i] < rating[m]) left_smaller++;
                else left_larger++;
            }
            for(int i=m+1; i<n; i++){
                if(rating[i] > rating[m]) right_larger++;
                else right_smaller++;
            }

            ans += (left_smaller * right_larger) + (left_larger * right_smaller);
        }
        return ans;
    }
};
