class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 1 -> 0 = 3;
        // 0 -> 1 = 4;
        if (board.empty() || board[0].empty()) return;
        int rows = board.size(), cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int alive_cnt = getAliveCnt(board, i, j, rows, cols);
                if (board[i][j] == 1) {
                    if (alive_cnt < 2 || alive_cnt > 3 ) board[i][j] = 3;
                } else {
                    if (alive_cnt == 3) board[i][j] = 4;
                }
            }
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 3) board[i][j] = 0;
                else if (board[i][j] == 4) board[i][j] = 1;
            }
        }
    }
private:
    int getAliveCnt(vector<vector<int>> &board, 
                    int row, int col, 
                    int rows, int cols) {
        int cnt = 0;
        
        for (int i = max(row - 1, 0); i <= min(row + 1, rows - 1); ++i) {
            for (int j = max(col - 1, 0); j <= min(col + 1, cols - 1); ++j) {
                if (i == row && j == col) continue;
                if (board[i][j] == 1 || board[i][j] == 3) ++cnt;
            }
        }
        return cnt;
    }
};
