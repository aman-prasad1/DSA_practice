class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        
        sort(pairs.begin(), pairs.end());

        auto p = pairs[0];
        int cnt = 1;
        for(auto pair : pairs){
            if(p[1] < pair[0]){
                p = pair;
                cnt++;
            }
            else if(p[1] > pair[1]){
                p = pair;
            }
        }

        return cnt;
    }
};
