class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<int>> mp(26, vector<int>(26, INT_MAX));
        for(int i=0; i<original.size(); i++){
            int from = original[i]-'a', to = changed[i]-'a';
            mp[from][to] = min(mp[from][to], cost[i]);
        }
        for(int i=0; i<26; i++){
            mp[i][i] = 0;
        }


        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                if(mp[i][k] < INT_MAX){
                    for(int j=0; j<26; j++){
                        if(mp[k][j] < INT_MAX){
                            mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                        }
                    }
                }
            }
        }

        long long ans = 0;
        for(int i=0; i<source.length(); i++){
            int src = source[i] - 'a';
            int dst = target[i] - 'a';
            if(src != dst){
                if(mp[src][dst] == INT_MAX) return -1;
                ans += mp[src][dst];
            }
        }

        return ans;
    }
};
