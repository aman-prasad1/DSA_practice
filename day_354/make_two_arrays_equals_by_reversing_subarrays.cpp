class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        ios::sync_with_stdio(NULL);
        cin.tie(NULL);

        unordered_map<int,int> mp1, mp2;

        for(int i=0; i<arr.size(); i++){
            mp1[target[i]]++;
            mp2[arr[i]]++;
        }
        for(int i=0; i<arr.size(); i++){
            if(mp2[target[i]] != mp1[target[i]]) return false;
        }
        return true;



        // APPROACH 2
        // sort(arr.begin(), arr.end());
        // sort(target.begin(), target.end());

        // return arr == target;
    }
};
