class Solution {
    void solve(int ind, vector<int>& temp, int n, int k, vector<vector<int>>& ans){
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i <= n; i++){
            temp.push_back(i);
            solve(i+1, temp, n, k, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, temp, n, k, ans);
        
        return ans;
    }
};
