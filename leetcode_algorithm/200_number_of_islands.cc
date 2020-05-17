class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] != '1')
                    continue;
                
                ++cnt;
                dfsMark(grid, row, col);
            }
        }
        
        return cnt;
    }
    
private:
    inline void dfsMark(vector<vector<char>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (row < 0 || row == rows || 
            col < 0 || col == cols || grid[row][col] != '1')
            return;
        
        grid[row][col] = '2';
        dfsMark(grid, row - 1, col);
        dfsMark(grid, row + 1, col);
        dfsMark(grid, row, col - 1);
        dfsMark(grid, row, col + 1);
    }
};