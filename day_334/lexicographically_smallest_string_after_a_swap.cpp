class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();

        for(int i=0; i<n-1; i++){
            int curr = s[i] - '0';
            int next = s[i+1] - '0';
            if((curr % 2 == 0 && next % 2 == 0) || (curr % 2 != 0 && next % 2 != 0)){
                if(curr > next){
                    swap(s[i], s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};
