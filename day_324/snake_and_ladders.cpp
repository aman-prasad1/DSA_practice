class Solution {
public:
    pair<int,int> intToPos(int square, int n){
        int r = (square-1) / n;
        int c = (square-1) % n;
        if(r%2){
            c = n - 1 - c;
        }
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        reverse(board.begin(), board.end());

        queue<pair<int,int>> q;
        q.push({1,0});
        vector<bool> visit(n*n, 0);

        while(!q.empty()){
            auto [square, moves] = q.front();
            q.pop();

            for(int i=1; i<7; i++){
                int nextSquare = square + i;
                auto [r,c] = intToPos(nextSquare, n);
                if(board[r][c] != -1){
                    nextSquare = board[r][c];
                }
                if(nextSquare == n*n){
                    return moves+1;
                }
                if(!visit[nextSquare]){
                    visit[nextSquare] = true;
                    q.push({nextSquare, moves+1});
                }
            }
        }
        return -1;
    }
};
