class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        auto cmp = [](pair<char, int>& a, pair<char,int>& b){
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char,int>>, decltype(cmp)> pq(cmp);

        for(auto &i : mp){
            pq.push({i.first, i.second});
        }

        string ans = "";


        while(!pq.empty()){
            pair<char,int> p = pq.top();
            pq.pop();
            for(int i=0; i<p.second; i++){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};