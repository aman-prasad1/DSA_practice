class Solution {
    vector<string> ans;
    void solve(int ind, string str, string s, vector<string>& wordDict){
        if(ind >= s.length()){
            if(str.length() > 0){
                ans.push_back(str.substr(1));
            }
            return ;
        }

        string temp = "";
        for(int i=ind; i < s.length(); i++){
            temp += s[i];
            if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
                solve(i+1, str + " " + temp, s, wordDict);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string str = "";
        solve(0, str, s, wordDict);

        return ans;
    }
};
