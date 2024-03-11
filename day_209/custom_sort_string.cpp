class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<int,int> mp;
        vector<bool> visited(26, false);

        for(char ch : s){
            mp[ch]++;
        }

        string ans = "";
        for(char ch : order){
            visited[ch - 'a'] = true;
            for(int i = 0; i < mp[ch]; i++){
                ans.push_back(ch);
            }
        }

        for(char ch : s){
            if(!visited[ch - 'a']){
                visited[ch - 'a'] = true;
                for(int i = 0; i < mp[ch]; i++){
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};