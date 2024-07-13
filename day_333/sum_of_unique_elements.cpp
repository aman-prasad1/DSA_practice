class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i : nums){
            mp[i]++;
        }
        for(int i : nums){
            if(mp[i] == 1) sum += i;
        }

        return sum;
    }
};
