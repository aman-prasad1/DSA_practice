class Solution {
    vector<vector<string>> ans;

    bool isSafe(int i, int j, int n, vector<string>& board){
        // checking for col j
        for(int r=0; r<i; r++){
            if(board[r][j] == 'Q')
                return false;
        }
        // checking for left diagonal
        int r = i-1, c = j-1;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--, c--;
        }
        // checking for right diagonal
        r = i-1, c = j+1;
        while(r >= 0 && c < n){
            if(board[r][c] == 'Q') return false;
            r--, c++;
        }
        return true;
    }

    void solve(int i, int n, vector<string>& board){
        if(i >= n){
            ans.push_back(board);
            return ;
        }

        for(int j=0; j<n; j++){
            bool safe = isSafe(i, j, n, board);
            if(safe){
                board[i][j] = 'Q';
                solve(i+1, n, board);
                board[i][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string temp = "";
        for(int i=0; i<n; i++) temp.push_back('.');
        vector<string> board(n, temp);

        solve(0, n, board);
        return ans;
    }
};
