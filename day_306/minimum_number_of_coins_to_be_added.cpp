class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        int n = coins.size();
        long long sum = 0;
        int ans = 0;
        int i = 0;
        while(sum < target){
            if(i < n && sum+1 >= coins[i]){
                sum += coins[i];
                i++;
            }
            else{
                ans++;
                sum += sum+1;
            }
        }
        return ans;
    }
};
