class Solution {
    int solve(string s, string str1, int point1, string str2, int point2){
        int points = 0;

        vector<char> stack1;
        vector<char> stack2;

        for(char c : s){
            if(!stack1.empty() && stack1.back() == str1[0] && c == str1[1]){
                stack1.pop_back();
                points += point1;
            }
            else{
                stack1.push_back(c);
            }
        }

        for(char c : stack1){
            if(!stack2.empty() && stack2.back() == str2[0] && c == str2[1]){
                stack2.pop_back();
                points += point2;
            }
            else{
                stack2.push_back(c);
            }
        }

        return points;
    }
public:
    int maximumGain(string s, int x, int y) {
        return (x > y)? solve(s, "ab", x, "ba", y) : solve(s, "ba", y, "ab", x);
    }
};
