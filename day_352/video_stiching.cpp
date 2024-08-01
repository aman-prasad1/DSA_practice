/*
INSTITUTION
  ans = 0 for the the answer,
  s = 0 for starting time of a clip
  e = 0 for ending time of a clip
  
APPROACH
  --> sort the clips array in non decreasing order
  --> initilize a while loop which will run till the (s < time)
  --> initilize a nested while loop to find all clips that start at or before s and update the end e to the farthest end time we can reach using these clips.
  --> after the nested loop ends if the s == e it means these is no clip was present between the ending of previous clip and the starting of next clip
  --> set the s = e and increment the ans by 1
*/


class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();

        sort(clips.begin(), clips.end());
        int ans = 0;
        int s = 0, e = 0, i = 0;
        while(s < time){
            while(i < n && clips[i][0] <= s){
                e = max(e, clips[i][1]);
                i++;
            }
            if(s == e) return -1;
            s = e;
            ans++;
        }
        return ans;
    }
};
