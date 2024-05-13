class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        int ans = (1<<(m-1))*n;

        for(int i=1;i<m;i++) {
            int curr=0;
            for(int j=0;j<n;j++) {
                if(a[j][i]==a[j][0])curr++;
            }
            ans += (1<<(m-i-1))*max(curr, n-curr);
        }
        return ans;
    }
};
