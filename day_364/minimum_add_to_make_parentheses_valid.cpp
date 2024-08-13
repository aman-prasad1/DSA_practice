class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for(char ch : s){
            if(st.empty() || ch == st.top()){
                st.push(ch);
                continue;
            }

            if(ch == '('){
                st.push(ch);
            }
            else{
                st.pop();
            }
        }

        return st.size();
    }
};
