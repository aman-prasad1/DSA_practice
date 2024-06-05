class Solution {
    int ans;

    bool isSafe(int i, int j, int n, vector<int>& board){
        // checking for col j
        for(int r=0; r<i; r++){
            if(board[r] == j)
                return false;
        }
        // checking for left diagonal
        int r = i-1, c = j-1;
        while(r >= 0 && c >= 0){
            if(board[r] == c){
                return false;
            }
            r--, c--;
        }
        // checking for right diagonal
        r = i-1, c = j+1;
        while(r >= 0 && c < n){
            if(board[r] == c) return false;
            r--, c++;
        }
        return true;
    }

    void solve(int i, int n, vector<int>& board){
        if(i >= n){
            ans++;
            return ;
        }

        for(int j=0; j<n; j++){
            bool safe = isSafe(i, j, n, board);
            if(safe){
                board[i] = j;
                solve(i+1, n, board);
                board[i] = -1;
            }
        }
    }
public:
    int totalNQueens(int n) {
        
        vector<int> board(n, -1);

        solve(0, n, board);
        return ans; 
    }
};
