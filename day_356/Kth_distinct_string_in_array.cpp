/*
    create a map of string , int, which stores the number of appearence of string in the array
    count all the appearence of the strings
    again traverse the array and if the string is visited only once decrement the k by 1, check if the k == 0 return the stirng
*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;

        for(string str : arr){
            mp[str]++;
        }

        for(string str : arr){
            if(mp[str] == 1){
                k--;
                if(k <= 0) return str;
            }
        }

        return "";
    }
};