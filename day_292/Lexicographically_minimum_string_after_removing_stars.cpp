class Solution {
public:
    string clearStars(string s) {
        priority_queue < pair<char,int>, vector <pair<char,int>> , greater < pair<char,int> >> pq;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '*'){
                auto top = pq.top();
                pq.pop();
                s[-top.second] = '#';
                s[i] = '#';
            }
            else{
                pq.push({s[i], -i});
            }
        }
        
        string ans = "";
        for(char ch : s){
            if(ch != '#') ans += ch;
        }
        return ans;
    }
};
