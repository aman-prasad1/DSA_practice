class Solution {
    bool solve(int i, int j, int k, vector<vector<char>>& board, string word){
        if(k == word.length()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;

        char temp = board[i][j];
        board[i][j] = '\0';

        if(solve(i+1, j, k+1, board, word) || solve(i-1, j, k+1, board, word) || 
           solve(i, j+1, k+1, board, word) || solve(i, j-1, k+1, board, word)){
            return true;
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(solve(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};