class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = positions.size();
        vector<pair<int,int>> robot_pos;
        for(int i=0; i<n; i++){
            robot_pos.push_back({positions[i], i});
        }
        sort(robot_pos.begin(), robot_pos.end());


        stack<pair<int,pair<char,int>>> st;
        for(auto &[pos, ind] : robot_pos){

            if(st.empty() || (!st.empty() && (st.top().second.first == directions[ind] || directions[ind] == 'R'))){
                st.push({healths[ind], {directions[ind], ind}});
                continue;
            }
            bool flag = false;
            while(directions[ind] == 'L' && st.top().second.first == 'R'){
                if(healths[ind] > st.top().first){
                    st.pop();
                    healths[ind]--;
                    flag = true;
                }
                else if(healths[ind] < st.top().first){
                    st.top().first -= 1;
                    if(st.top().first <= 0) st.pop();
                    flag = false;
                    break;
                }
                else{
                    st.pop();
                    flag = false;
                    break;
                }
                if(st.empty()){
                    st.push({healths[ind], {directions[ind], ind}});
                    flag = false;
                    break;
                }
            }
            if(flag){
                st.push({healths[ind], {directions[ind], ind}});
            }
        }

        vector<int> ans;
        vector<pair<int,int>> temp;
        while(!st.empty()){
            temp.push_back({st.top().second.second, st.top().first});
            st.pop();
        }

        sort(temp.begin(), temp.end());
        for(auto i : temp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
