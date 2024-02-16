class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();

        // step 1: sort the arr
        sort(arr.begin(), arr.end());

        // step 2: count the appearence of every element in arr and push it in the vector
        int cnt = 1;
        vector<pair<int,int>> mp;
        for(int i=1; i<n; i++){
            if(arr[i] != arr[i-1]){
                mp.push_back(make_pair(arr[i-1], cnt));
                cnt = 1;
            }
            else cnt++;
        }
        mp.push_back(make_pair(arr[n-1], cnt));

        // sort the vector mp according to the second number
        sort(mp.begin(), mp.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        // deleting elements
        int ans = mp.size();
        for(auto i : mp){
            cout<< i.second;
            if(i.second <= k){
                ans--;
                k -= i.second;
            }
            else{
                break;
            }
        }
        return ans;
    }
};