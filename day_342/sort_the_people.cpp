class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        unordered_map<int,int> mp;

        for(int i=0; i<heights.size(); i++){
            mp[heights[i]] = i;
        }

        sort(heights.begin(), heights.end(), greater<int>());

        for(auto h : heights){
            ans.push_back(names[mp[h]]);
        }

        return ans;
    }
};