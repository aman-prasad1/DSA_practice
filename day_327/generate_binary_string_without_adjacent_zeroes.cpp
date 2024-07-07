class Solution {
    vector<string> ans;
    void solve(int n, string str, int prev){
        if(str.length() == n){
            ans.push_back(str);
            return;
        }

        if(prev == 0){
            solve(n, str+"1", 1);
        }
        else{
            solve(n, str+"0", 0);
            solve(n, str+"1", 1);
        }
    }
public:
    vector<string> validStrings(int n) {
        solve(n, "0", 0);
        solve(n, "1", 1);
        return ans;
    }
};
