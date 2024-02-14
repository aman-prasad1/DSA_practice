class Solution {
public:
    int pivotInteger(int n) {
        
        int ans = -1;
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += i;
            // calculating the sum of series from i
            int a1 = i;
            int terms = n-i+1;
            int S = (terms * (a1 + n))/2;

            if(S == sum){
                ans = i;
                break;
            }
        }
        return ans;
    }
};