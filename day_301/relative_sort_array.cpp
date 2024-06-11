class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(int num : arr1){
            mp[num]++;
        }
        for(int num : arr2){
            mp2[num]++;
        }

        sort(arr1.begin(), arr1.end());

        vector<int> ans;
        for(int num : arr2){
            for(int i=0; i<mp[num]; i++){
                ans.push_back(num);
            }
        }

        for(int num : arr1){
            if(mp2.find(num) == mp2.end()){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
