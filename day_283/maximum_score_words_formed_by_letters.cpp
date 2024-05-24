class Solution {
    int solve(int ind, vector<int> cnt, vector<int>& score, vector<string>& words){
        if(ind >= words.size()) return 0;

        // checking for word at ind can form from remaining letters
        int scr = 0;
        for(char ch : words[ind]){
            if(cnt[ch - 'a'] == 0) return 0;
            cnt[ch - 'a']--;
            scr += score[ch - 'a'];
        }
        // recursive call
        int ans = 0;
        for(int i=ind+1; i < words.size(); i++){
            ans = max(ans, scr + solve(i, cnt, score, words));
        }
        return max(ans, scr);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26, 0);
        // counting the availabe letters
        for(char ch : letters){
            cnt[ch - 'a']++;
        }

        int ans = 0;
        for(int i=0; i<words.size(); i++){
            ans = max(ans, solve(i, cnt, score, words));
        }
        return ans;
    }
};
