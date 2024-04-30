class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> count;
        int mask = 0;
        count[0] = 1;
        long long ans = 0;
        for(char c : word) {
            mask ^= 1 << (c - 'a');
            ans += count[mask];
            for(int i = 0; i < 10; i++) {
                ans += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }
        return ans;
    }
};
