class Solution {
    bool palindrome(string s){
        int n = s.length();
        int r = n-1;
        for(int i=0; i<n/2; i++){
            if(s[i] != s[r-i]) return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string s : words){
            bool check = palindrome(s);

            if(check){
                return s;
            }
        }
        return "";
    }
};