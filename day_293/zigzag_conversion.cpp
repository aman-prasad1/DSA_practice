class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.length();

        int k = 0;
        vector<string> v(numRows, "");
        v[0].push_back(s[k++]);
        while(k < n){
            for(int i=1; i<numRows && k<n; i++){
                v[i].push_back(s[k]);
                k++;
            }
            for(int i=numRows-2; i>=0 && k<n; i--){
                v[i].push_back(s[k]);
                k++;
            }
        }
        string ans = "";
        for(string str : v){
            ans += str;
        }
        return ans;
    }
};
