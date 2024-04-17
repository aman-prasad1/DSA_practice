class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, sum = 0;

        for(int i : gain){
            sum += i;
            ans = max(ans, sum);
        }
        return ans;
    }
};