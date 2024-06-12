/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* solve(vector<vector<int>>& grid, int r, int c, int n){
        int same = true;
        for(int i=r; i<n+r; i++){
            for(int j=c; j<n+c; j++){
                if(grid[r][c] != grid[i][j]){
                    same = false;
                    break;
                }
            }
        }
        if(same){
            return new Node(grid[r][c], true);
        }

        n = n/2;

        Node* topleft = solve(grid, r, c, n);
        Node* topright = solve(grid, r, c+n, n);
        Node* bottomleft = solve(grid, r+n, c, n);
        Node* bottomright = solve(grid, r+n, c+n, n);

        Node* ans = new Node(0, false, topleft, topright, bottomleft, bottomright);
        return ans;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
