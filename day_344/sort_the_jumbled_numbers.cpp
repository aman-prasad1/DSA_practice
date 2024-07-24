class Solution {
    int solve(int num, vector<int>& mapping){
        string digits = to_string(num);
        for(char& ch : digits){
            ch = '0' + mapping[ch - '0'];
        }
        return stoi(digits);
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        unordered_map<int,int> mp;

        for(int num : nums){
            if(mp.find(num) == mp.end()){
                mp[num] = solve(num, mapping);
            }
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            return mp[a] < mp[b];
        });

        return nums;
    }
};
