class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(n == 1) return 1;
        int i = 0, j = n-1;

        while(i < j){
            if(s[i] == s[j]){
                // finding prefix
                while(i+1 < n && s[i+1] == s[i]){
                    i++;
                }
                i++;

                // finding suffix
                while(j-1 >= 0 && s[j-1] == s[j]){
                    j--;
                }
                j--;
            }
            else{
                break;
            }
        }

        
        return (j - i + 1 < 0)? 0 : j-i+1;
    }
};