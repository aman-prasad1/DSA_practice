class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        int i = 0, j = 0;
        while(i < n && j < m){
            ans[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];

            if(rowSum[i] == 0){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};
