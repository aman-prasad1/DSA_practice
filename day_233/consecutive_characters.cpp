class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int cnt = 1;
        char prev = s[0];
        for(int i = 1; i < s.length(); i++){
            if(s[i] == prev){
                cnt++;
            }
            else{
                ans = max(ans, cnt);
                prev = s[i];
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};