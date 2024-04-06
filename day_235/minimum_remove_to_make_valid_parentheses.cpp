class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')') {
                if (cnt == 0) s[i] = '*';
                else cnt--;
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            if (cnt > 0 && s[i] == '(') {
                s[i] = '*';
                cnt--;
            }
        }
        
        string result = "";
        for (char c : s) {
            if (c != '*') result += c;
        }
        return result;
    }
};