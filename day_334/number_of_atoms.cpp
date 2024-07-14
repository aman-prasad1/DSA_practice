class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        int i, j, k;
        stack<pair<string, int>> st;

        for(i=0; i<n; i++){
            char ch = formula[i];

            if(isupper(ch)){
                string element = "";
                element += ch;
                for(j=i+1; j<n; j++){
                    ch = formula[j];
                    if(!islower(ch)) break;
                    element += ch;
                }

                string sdigit = "";
                for(k=j; k<n; k++){
                    ch = formula[k];
                    if(!isdigit(ch)) break;
                    sdigit += ch;
                }

                if(sdigit == "") sdigit = "1";
                int digit = stoi(sdigit);

                st.push({element, digit});
                i = k-1;
            }

            else if(ch == '('){
                st.push({"(", -1});
            }

            else if(ch == ')'){
                string sdigit = "";
                for(j=i+1; j<n; j++){
                    ch = formula[j];
                    if(!isdigit(ch)) break;
                    sdigit += ch;
                }

                if(sdigit == "") sdigit = "1";
                int digit = stoi(sdigit);

                vector<pair<string, int>> temp;
                pair<string, int> openingPair = {"(", -1};
                while(st.top() != openingPair){
                    pair<string, int> p = st.top();
                    st.pop();
                    temp.push_back({p.first, p.second * digit});
                }
                st.pop();

                while(temp.size() > 0){
                    st.push(temp.back());
                    temp.pop_back();
                }
                i = j-1;
            }
        }

        map<string, int> mp;
        while(!st.empty()){
            pair<string, int> p = st.top();
            st.pop();
            mp[p.first] += p.second;
        }

        string ans = "";
        for(auto p : mp){
            string element = p.first;
            string sdigit = to_string(p.second);
            if(sdigit == "1") sdigit = "";
            ans += element + sdigit;
        }

        return ans;
    }
};
