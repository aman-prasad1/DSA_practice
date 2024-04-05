class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        ans.push_back(s[0]);
        int ind = 0; // denotes the last element index in the ans string
        for(int i=1; i<s.length(); i++){
            if(s[i]-'a' == ans[ind]-'A' || s[i]-'A' == ans[ind]-'a'){
                ans.pop_back();
                ind--;
                if(ind < 0 && i+1 < s.length()){
                    ans.push_back(s[i+1]);
                    i++;
                    ind++;
                }
            }
            else{
                ans.push_back(s[i]);
                ind++;
            }
        }
        return ans;
    }
};