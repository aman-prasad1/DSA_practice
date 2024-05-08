class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        for(int i=0; i<26; i++) children[i] = NULL;
        isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root, *curr;

    Trie() {
        root = new TrieNode('\0');    
    }
    
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    void insert(string word) {
        insertUtil(root, word);
    }

    
    void search(TrieNode* curr, string& word, vector<string>& ans){
        if(ans.size() == 3) return;
        if(curr->isTerminal) ans.push_back(word);

        for(char c='a'; c<='z'; c++){
            if(curr->children[c-'a']){
                word += c;
                search(curr->children[c-'a'], word, ans);
                word.pop_back();
            }
        }

    }
    vector<string> searchSugg(string word){
        curr = root;
        vector<string> ans;

        for(char ch : word){
            if(!curr->children[ch - 'a']) return ans;
            curr = curr->children[ch - 'a'];
        }
        search(curr, word, ans);
        return ans;
    }
    
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();

        for(string str : products){
            root->insert(str);
        }
        
        vector<vector<string>> ans;
        string word = "";
        for(char ch : searchWord){
            word += ch;
            ans.push_back(root->searchSugg(word));
        }
        return ans;
    }
};
