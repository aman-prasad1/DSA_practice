class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxi = 0;

        for(int i=0; i<k; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                maxi++;
            }
        }

        int i = 0, j = k, temp = maxi;

        while(j < n){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                temp--;
            }
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                temp++;
            }
            maxi = max(maxi, temp);
            i++;
            j++;
        }

        return maxi;
    }
};