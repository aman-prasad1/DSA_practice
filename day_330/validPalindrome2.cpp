class Solution {
public:
    bool validPalindrome(string s) {
        bool check1 = true, check2 = true;

        int i = 0, j = s.length()-1;
        while(i <= j){
            if(s[i] == s[j]){
                i++, j--;
            }
            else{
                int l = i, r = j;
                while(i < j){
                    if(s[i] != s[j-1]){
                        check1 = false;
                        break;
                    }
                    i++, j--;
                }
                while(l+1 <= r){
                    if(s[l+1] != s[r]){
                        check2 = false;
                        break;
                    }
                    l++, r--;
                }
                return check1 || check2;
            }
        }
        return true;
    }
};
