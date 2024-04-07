class Solution {
public:
    bool checkValidString(string s) {
        // here we have 3 choices to put '(' or ')' or ''
        int cnt1 = 0, cnt2 = 0;

        for(char ch : s){
            if(ch == '('){
                cnt1++;
                cnt2++;
            }
            else if(ch == ')'){
                cnt1--;
                cnt2--;
            }
            else{
                cnt1--;
                cnt2++;
            }
            if(cnt2 < 0) return false; // if cnt2 < 0; it means ')' cnt is more in left side. i.e --> ")))((("
            if(cnt1 < 0) cnt1 = 0; // it means we converte '*' to ')' in large amount
        }
        return cnt1 == 0;
    }
};