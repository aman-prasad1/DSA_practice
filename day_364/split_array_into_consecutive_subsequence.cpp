// created two maps, "freq" to store frequency of elements and "need" to store elements which can be added to the end of the previosly created subsequence

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq, need;

        for(int num : nums){
            freq[num]++;
        }

        for(int num : nums){
            // continue if the element is already used by another sub sequence
            if(freq[num] <= 0) continue;

            // if the need[num] > 0 it means there was already a subsequence present which ends with num - 1. example:- [1, 2, 3] is a previously created subsequence and the num is 4,
            // we could just add it to the subsequence [1, 2, 3, 4]
            if(need[num] > 0){
                need[num]--;
                freq[num]--; // the num was used in a sequence so we can decrease its count
                need[num+1]++; // now the subsequence ends with 4 and we can add 5 to it if present in the array
            }

            // if the need of num is 0, we have to create a new subsequence starting with num
            else if(freq[num+1] > 0 && freq[num+2] > 0){
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
                need[num+3]++;
            }
            else return false;
        }

        return true;
    }
};
