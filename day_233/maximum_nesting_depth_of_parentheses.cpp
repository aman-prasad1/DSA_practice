class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        if(n == 1) return 0;

        int ans = 0, maxi = 0;
        for(char ch : s){
            if(ch == '('){
                maxi++;
            }
            else if(ch == ')'){
                maxi--;
            }
            ans = max(ans, maxi);
        }
        if(maxi == 0) return ans;
        return 0;
    }
};