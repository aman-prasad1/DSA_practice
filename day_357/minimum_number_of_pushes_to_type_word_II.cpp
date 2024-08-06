class Solution {
public:
    int minimumPushes(string word) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = word.length();
        vector<int> mp(26, 0);

        for(int i=0; i<n; i++){
            mp[word[i] - 'a']++;
        }

        sort(mp.begin(), mp.end(), greater<int>());

        int pushes = 0;
        for(int i=0; i<26; i++){
            pushes += mp[i] * (i/8 + 1);
        }

        return pushes;
    }
};
