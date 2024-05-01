class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();

        int i = 0, j = 0;
        while(j < n && word[j] != ch){
            j++;
        }

        while(j < n && i < j){
            swap(word[i++], word[j--]);
        }
        return word;
    }
};
