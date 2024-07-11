// APPROACH 1 RECURSION

class Solution {
    int i = 0;
    string solve(string s){
        string ans = "";

        while(i < s.length()){
            if(s[i] == '('){
                i++;
                ans += solve(s);
            }
            else if(s[i] == ')'){
                i++;
                reverse(ans.begin(), ans.end());
                return ans;
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
public:
    string reverseParentheses(string s) {
        return solve(s);                
    }
};

// APPROACH 2 USING STACK

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            if(ch == ')'){
                string temp = "";
                while(!st.empty() && st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(char c : temp){
                    st.push(c);
                }
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
