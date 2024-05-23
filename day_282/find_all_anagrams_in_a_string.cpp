class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cnt_s(26, 0);
        vector<int> cnt_p(26, 0);
        vector<int> ans;
        if(s.size() < p.size()) return ans;

        for(char ch : p)
            cnt_p[ch - 'a']++;

        int i = 0, j = 0;
        while(j < s.size()){
            cnt_s[s[j] - 'a']++;
            if(j-i+1 == p.length()){
                if(cnt_s == cnt_p) ans.push_back(i);
            }
            if(p.length() > j-i+1){
                j++;
            }
            else{
                cnt_s[s[i] - 'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};
