// Time Complexity :- O(n^3)
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         if(n <= 2) return n;

//         int ans = 2;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int count = 2;
//                 for(int k=0; k<n; k++){
//                     if(k != i && k != j){
//                         if((points[j][1]-points[i][1])*(points[j][0]-points[k][0]) == (points[j][1]-points[k][1])*(points[j][0]-points[i][0])){
//                             count++;
//                         }
//                     }
//                 }
//                 ans = max(ans, count);
//             }
//         }
//         return ans;
//     }
// };

// Time Complexity :- O(n^2)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        unordered_map<double,int> mp;
        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double x1 = points[i][0];
                double x2 = points[j][0];
                double y1 = points[i][1];
                double y2 = points[j][1];
                double slope;

                if(x1 == x2){
                    slope = INT_MAX;
                }
                else{
                    slope = (y2-y1) / (x2-x1);
                }
                mp[slope]++;
                ans = max(ans, mp[slope]+1);
            }
            mp.clear();
        }
        return ans;
    }
};
