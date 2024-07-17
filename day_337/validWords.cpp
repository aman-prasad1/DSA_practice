class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false;

        vector<int> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int vowelcnt = 0, cons = 0;

        for(char ch : word){
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')){
                if(find(vowels.begin(), vowels.end(), ch) != vowels.end()) vowelcnt = 1;
                else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) cons = 1;
                else if(!(ch >= '0' && ch <= '9')) return false;
            }
            else{
                return false;
            }
        }

        return (vowelcnt == 1 && cons == 1)? 1 : 0;
    }
};