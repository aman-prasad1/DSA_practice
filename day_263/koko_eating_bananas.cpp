class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int s = 1, e = *max_element(piles.begin(), piles.end());
        // since mini is the minimum ans possible and maxi is the maximum ans possible
        int mid = s + (e-s)/2;
        int ans = INT_MAX;
        while(s < e){
            int temp = 0;
            for(int pile : piles){
                temp += ((pile-1)/mid) +1;
            }

            if(temp <= h){
                e = mid;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
};
