class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int ans = 0;
        vector<int> visited(n,0);
        unordered_map<int,int> mp;
        for(int i=0;i<n;++i) mp[row[i]] = i;
        
        for(int i=0;i<n;i+=2){
            if(!visited[i]){
                int pa = i;
                int pb = -1;
                int loopEdge = 0;
                while(!visited[pa]){
                    if(row[pa]%2==0) pb = mp[row[pa]+1];
                    else pb = mp[row[pa]-1];
                    visited[pa] = visited[pb] = 1;
                    pa = pb;
                    pb = -1;
                    if(pa%2==0) ++pa;
                    else --pa;
                    ++loopEdge;
                }
                ans += loopEdge-1;
            }
        }

        return ans;
    }
};