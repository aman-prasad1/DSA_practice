class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();

        vector<int> cnt(26, INT_MAX);
        for(string word : words){
            vector<int> temp(26, 0);
            // counting charactera in words
            for(char ch : word){
                temp[ch-'a']++;
            }
            // taking intersection of ans and the temp
            for(int i=0; i<26; i++){
                cnt[i] = min(cnt[i], temp[i]);
            }
        }

        vector<string> ans;
        for(int i=0; i<26; i++){
            for(int j=0; j<cnt[i]; j++){
                string temp = "";
                temp += 'a'+i;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
