// class Solution {
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
//         unordered_map<string, bool> mp;
//         for(string str : dictionary){
//             mp[str] = true;
//         }

//         string ans = "";
//         int i = 0;
//         string temp = "";
//         while(i < sentence.length()){
//             char ch = sentence[i];
//             if(ch == ' '){
//                 ans += temp;
//                 ans += " ";
//                 temp = "";
//             }
//             else{
//                 temp.push_back(ch);
//                 if(mp[temp]){
//                     ans += temp;
//                     ans += " ";
//                     temp = "";
//                     while(i < sentence.length() && sentence[i] != ' ') i++;
//                 }
//             }
//             i++;
//         }
//         if(!temp.empty()){
//             ans += temp;
//         }
//         else ans.pop_back();
//         return ans;
//     }
// };

class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;
    string word;

    TrieNode() {
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        word = "";
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void build(vector<string> &words) {
        for(string word : words) {
            TrieNode* current = root;
            for(char c: word) {
                if(current->children[c-'a']==NULL) {
                    current->children[c-'a'] = new TrieNode();
                }
                current = current->children[c-'a'];
            }
            current->isTerminal = true;
            current->word = word;
        }
    }

    string findShortestPrefix(string word) {
        TrieNode* current = root;
        for(char c : word) {
            if(current->isTerminal) {
                return current->word;
            }

            if(current->children[c-'a']==NULL) {
                return "";
            } else {
                current = current->children[c-'a'];
            }
        }
        return "";
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        trie.build(dictionary);

        string word = "";
        string replacedSentence = "";
        for(char c : sentence) {
            if(c==' ') {
                string shortestPrefix = trie.findShortestPrefix(word);
                if(shortestPrefix.length() > 0) {
                    replacedSentence += shortestPrefix;
                } else {
                    replacedSentence += word;
                }
                replacedSentence += c;
                word = "";
            } else {
                word +=c;
            }
        }

        if(word.length() > 0) {
            string shortestPrefix = trie.findShortestPrefix(word);
            if(shortestPrefix.length() > 0) {
                replacedSentence += shortestPrefix;
            } else {
                replacedSentence += word;
            }
        }

        return replacedSentence;
    }
};
