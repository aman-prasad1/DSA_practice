class Solution {
public:
    int n, m;
    vector<vector<int>> ans;
    void dfs(int i, int j, int& r1, int& c1, int& r2, int& c2,vector<vector<int>>& land){
        if (!((0<=i)&&(i<n)&&(0<=j)&&(j<m))) return;
        if (land[i][j]==1){
            land[i][j]=-1;
            r1=min(r1, i), c1=min(c1, j), r2=max(r2, i), c2=max(c2, j);
            dfs(i+1,j, r1, c1, r2, c2, land);
            dfs(i,j+1, r1, c1, r2, c2, land);
            dfs(i-1,j, r1, c1, r2, c2, land);
            dfs(i,j-1, r1, c1, r2, c2, land);
        }          
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(land[i][j]==1){
                    int r1=i, c1=j, r2=i, c2=j;
                    dfs(i, j, r1, c1, r2, c2, land);
                    ans.push_back({r1, c1, r2, c2});   
                }
            }
        return ans;
    }
};