class Solution {
public:
    int arrangeCoins(int n) {

        // int row = 1;
        // for(int row=1; row < n; row++){
        //     long long sum = (row * (long long)(row+1))/2;
        //     if(sum == n) return row;
        //     if(sum > n) return row-1;
        // }
        // return 1;

        // APPROACH 2
        long long s = 1, e = n;
        while(s <= e){
            long long mid = s + (e-s)/2;
            long long coins = (mid * (long long) (mid+1))/2;
            if(coins == n) return mid;
            else if(coins > n) e = mid-1;
            else s = mid+1;
        }
        return e;
    }
};
