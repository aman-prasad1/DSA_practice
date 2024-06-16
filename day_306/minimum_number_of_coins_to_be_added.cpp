class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int size = coins.size();
        long long sum = 0;
        int patch = 0;
        int i = 0;
        while(sum < target){
            if(i < size && sum+1 >= coins[i]){
                sum += coins[i];
                i++;
            }
            else{
                patch++;
                sum += sum+1;
            }
        }
        return patch;
    }
};
