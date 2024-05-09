class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        
        sort(happiness.begin(), happiness.end(), greater<int>());

        for(int i=0; i<k; i++){
            int temp = happiness[i] - i;
            if(temp > 0) ans += temp;
            else break;
        }
        return ans;
    }
};
