class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& v, int sum, int target, vector<int>& candidates, int i){
        if(sum == target){
            ans.push_back(v);
            return;
        }
        if(sum > target){
            return;
        }

        for(int j = i; j < candidates.size() ;j++){
            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }
            v.push_back(candidates[j]);
            solve(ans,v,sum,target-candidates[j],candidates,j+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        int sum = 0;

        solve(ans,v,sum,target,candidates,0);

        return ans;
    }
};
