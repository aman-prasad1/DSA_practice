class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        int work_days = 0;
        for(int i=0; i<meetings.size(); i++){
            int st = meetings[i][0];
            int end = meetings[i][1];
            int j = i+1;
            while(j < meetings.size()){
                if(end < meetings[j][0]){
                    i = j-1;
                    break;
                }
                else if(end >= meetings[j][0]){
                    end = max(end, meetings[j][1]);
                }
                j++;
                i = j;
            }
            work_days += end - st + 1;
        }
        return days - work_days;
    }
};
