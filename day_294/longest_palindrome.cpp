class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char,int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        int ans = 0;
        for(char ch : s){
            ans += (mp[ch]/2) * 2;
            mp.erase(ch);
        }
        if(ans != n) return ans+1;
        return ans;
    }
};
