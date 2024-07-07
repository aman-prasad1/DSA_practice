class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string temp = s;
        for(int i=0; i<n; i++){
            temp[i] = s[(i+k)%n];
        }

        return temp;
    }
};
