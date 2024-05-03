class Solution {
    // int solve(int spell, vector<int>& potions, long long success){
    //     int m = potions.size();
    //     int s = 0, e = m-1, mid = s + (e-s)/2;

    //     while(s <= e){
    //         if(mid+1 < m && (long long) spell * potions[mid] < success && (long long) spell * potions[mid+1] >= success){
    //             return mid+1;
    //         }
    //         else if((long long) spell * potions[mid] < success){
    //             s = mid+1;
    //         }
    //         else{
    //             e = mid-1;
    //         }
    //         mid = s + (e-s)/2;
    //     }
    //     return s;
    // }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();

        vector<int> ans(n);

        for(int i=0; i<n; i++){
            // int j = solve(spells[i], potions, success);
            int j = lower_bound(potions.begin(),potions.end(),ceil((double)success / spells[i]))-potions.begin();
            ans[i] = m-j;
        }
        return ans;
    }
};
