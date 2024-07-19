class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        for(int i=0; i<m; i++){
            bool flag = true;
            int max_j = 0;
            for(int j=0; j<n; j++){
                if(matrix[i][j] < matrix[i][max_j]){
                    max_j = j;
                }
            }
            for(int ind=0; ind<m; ind++){
                if(matrix[ind][max_j] > matrix[i][max_j]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans.push_back(matrix[i][max_j]);
            }
        }

        return ans;
    }
};
