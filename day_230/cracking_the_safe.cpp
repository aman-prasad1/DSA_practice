class Solution {
    bool dfs(string& ans, int n, int k, unordered_set<string>& visited, int total){
        if(visited.size() == total) return true;
        string temp = ans.substr(ans.size()-(n-1), n-1);
        
        string newStr = temp + '0';
        for(int i=0; i<k; i++){
            newStr[n-1] = (i + '0');
            if(!visited.count(newStr)) {
                visited.insert(newStr);
                ans += (i + '0');
                if(dfs(ans, n, k, visited, total))
                    return true;

                visited.erase(newStr);
                ans.pop_back();
            }
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        string ans = string(n, '0');
        unordered_set<string> visited;
        visited.insert(ans);
        dfs(ans, n, k, visited, pow(k, n));
        return ans;
    }
};