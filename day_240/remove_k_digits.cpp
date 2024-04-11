class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        
        for (char digit : num) {
            while (!s.empty() && k > 0 && s.top() > digit) {
                s.pop();
                k--;
            }
            s.push(digit);
        }
        
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        
        string temp;
        while (!s.empty()) {
            temp += s.top();
            s.pop();
        }
        reverse(temp.begin(), temp.end());

        int m = temp.size();
        string ans = "";
        for (int i = 0; i < m; i++) {
            if (temp[i] == '0' && ans.empty()) {
                continue;
            } else {
                ans.push_back(temp[i]);
            }
        }
        if (ans.size() == 0)
            ans.push_back('0');
        return ans;
    }
};
