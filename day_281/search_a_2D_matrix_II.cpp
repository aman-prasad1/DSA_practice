// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         for(int i=0; i<m; i++){
//             if(matrix[i][0] <= target && matrix[i][n-1] >= target){
//                 int s = 0, e = n-1;
//                 while(s <= e){
//                     int mid = s + (e-s)/2;
//                     if(matrix[i][mid] == target) return true;
//                     else if(matrix[i][mid] < target) s = mid+1;
//                     else e = mid-1;
//                 }
//             }
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = m-1, col = 0;
        while(row >= 0 && col < n){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) row--;
            else col++;
        }
        return false;
    }
};
