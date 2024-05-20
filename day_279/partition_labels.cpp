class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastOccurance;
        vector<int> ans;
        for(int i=0; i<s.length(); i++){
            lastOccurance[s[i]] = i;
        }

        int i = 0; 
        while(i < s.length()){
            int start = i;
            int end = lastOccurance[s[i]];
            while(i < s.length() && i < end){
                if(lastOccurance[s[i]] > end){
                    end = lastOccurance[s[i]];
                }
                i++;
            }
            ans.push_back(end-start+1);
            i++;
        }
        return ans;
    }
};
