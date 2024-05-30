class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;

        for(int i=0; i<arr.size()-1; i++){
            int temp = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                temp ^= arr[j];
                if(temp == 0){
                    ans += j - i;
                }
            }
        }
        return ans;
    }
};
