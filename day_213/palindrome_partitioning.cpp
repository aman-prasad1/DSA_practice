class Solution {
public:
    bool isPalindrome(const string& s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void solve(int i, int j , string& s,vector<string>& temp,vector<vector<string>>& ans){
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int k = i; k < j; k++){
            if(isPalindrome(s,i,k)){
                temp.push_back(s.substr(i,k-i+1));
                solve(k+1,j,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.size()==0) return {{}};
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(0,s.length(),s,temp,ans);
        
        return ans;
    }
};