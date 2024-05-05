class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int ind, int k, int n){
        if(n == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<=n, i<=9; i++){
            temp.push_back(i);
            solve(i+1, k, n-i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1, k, n);
        return ans;
    }
};
