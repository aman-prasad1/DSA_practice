class Solution {
    bool isPossible(vector<int>& position, int dist, int m){
        int prev = position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i]-prev >= dist){
                m--;
                prev = position[i];
            }
        }
        return m <= 1;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int n = position.size();
        sort(position.begin(), position.end());

        int s = 0, e = position[n-1], ans = 1;

        while(s <= e){
            int mid = s+(e-s)/2;

            if(isPossible(position, mid, m)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};
