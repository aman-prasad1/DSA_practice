class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> cnt(2,0);
        for(int std : students){
            cnt[std]++;
        }

        int ans = students.size();
        for(int sandwich : sandwiches){
            if(!cnt[sandwich] || !ans) return ans;
            cnt[sandwich]--;
            ans--;
        }
        return ans;
    }
};