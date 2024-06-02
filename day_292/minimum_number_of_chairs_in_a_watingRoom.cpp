class Solution {
public:
    int minimumChairs(string s) {
        int maxi = 0;
        int curr = 0;
        
        for(char ch : s){
            if(ch == 'E'){
                curr++;
            }
            else{
                curr--;
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};
