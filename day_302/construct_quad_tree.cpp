class Solution {
public:
    bool sameVal(vector<vector<int>>& grid, int x, int y, int size)
    {
        for(auto i = x; i<x+size; ++i)
        {
            for(auto j=y; j<y+size; ++j)
            {
                if(grid[i][j] != grid[x][y])
                {
                    return false;
                }
            }
        }
        return true;
    }
    void rec(Node* root, vector<vector<int>>& grid, int x, int y, int size)
    {
        if(sameVal(grid, x, y, size))
        {
            root->val = grid[x][y];
            root->isLeaf=true;
            return;
        }
        int new_size = size/2;
        
        root->topLeft = new Node();
        rec(root->topLeft, grid, x, y, new_size);
        
        root->topRight = new Node();
        rec(root->topRight, grid, x, y+new_size, new_size);
        
        root->bottomLeft = new Node();
        rec(root->bottomLeft, grid, x+new_size, y, new_size);

        root->bottomRight = new Node();
        rec(root->bottomRight, grid, x+new_size, y+new_size, new_size);
    }
    Node* construct(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        auto root = new Node();
        rec(root, grid, 0, 0, n);
        return root;
    }
};
