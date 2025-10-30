class Solution {
  public:
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O') return;
        
        grid[i][j] = '#'; // mark safe 'O'
        
        // move in all 4 directions
        dfs(i+1, j, grid, n, m);
        dfs(i-1, j, grid, n, m);
        dfs(i, j+1, grid, n, m);
        dfs(i, j-1, grid, n, m);
    }

    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Step 1: Mark border-connected 'O's
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') dfs(i, 0, grid, n, m);
            if (grid[i][m-1] == 'O') dfs(i, m-1, grid, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') dfs(0, j, grid, n, m);
            if (grid[n-1][j] == 'O') dfs(n-1, j, grid, n, m);
        }
        
        // Step 2: Flip surrounded 'O' to 'X' and revert safe '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                else if (grid[i][j] == '#') grid[i][j] = 'O';
            }
        }
    }
};
