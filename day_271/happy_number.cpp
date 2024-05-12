class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> mp;

        while(n != 1){
            if(mp[n] == true) return false;
            mp[n] = true;
            int sqSum = 0;
            while(n){
                int digit = n % 10;
                sqSum += digit * digit;
                n /= 10;
            }
            n = sqSum;
        }
        return true;
    }
};
