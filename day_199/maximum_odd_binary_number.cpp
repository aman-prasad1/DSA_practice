class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();

        if(n == 1) return s;

        int cnt_1 = 0;
        for(char ch : s){
            if(ch == '1'){
                cnt_1++;
            }
        }

        string ans = "";

        for(int i=0; i<n; i++){
            if(cnt_1 > 1){
                ans.push_back('1');
                cnt_1--;
            }
            else{
                ans.push_back('0');
            }
        }

        if(cnt_1 == 1) ans[n-1] = '1';
        return ans;
    }
};