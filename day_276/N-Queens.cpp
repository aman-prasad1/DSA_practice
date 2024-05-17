class Solution {
    vector<vector<string>> ans;

    bool isSafe(int i, int j, int n, vector<string>& board){
        // checking for col j
        for(int r=0; r<n; r++){
            if(board[r][j] == 'Q')
                return false;
        }
        // checking for diagonal from top left to bottom right
        int mini = min(i, j);
        int r = i-mini, c = j-mini;
        while(r < n && c < n){
            if(board[r][c] == 'Q' && r != i && c != j) return false;
            r++, c++;
        }
        // checking for diagonal from top right to bottom left
        int temp = i-n+j+1;
        r = (temp <= 0)? 0:temp;
        c = (i+j >= n)? n-1 : i+j;
        while(r < n && c >= 0){
            if(board[r][c] == 'Q' && r != i && c != j) return false;
            r++, c--;
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
