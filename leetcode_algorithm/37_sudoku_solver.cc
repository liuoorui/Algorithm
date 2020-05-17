#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(grid, 0, sizeof(grid));
        for (int i=0; i<9; ++i)
            for (int j=0; j<9; ++j) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                set(i, j, num, 1);
            }

        dfs(board, 0, 0);
    }
private:
    bool rows[9][9];
    bool cols[9][9];
    bool grid[9][9];
    bool dfs(vector<vector<char>>& board, int i, int j) {
        while (i<9 && j<9 && board[i][j]!='.') {
            ++j;
            if (j == 9) {
                ++i;
                j = 0;
            } 
        }
        if (i == 9) return true;

        for (int num=1; num<=9; ++num) {
            if (rows[i][num-1] || cols[j][num-1] || 
                grid[i/3*3+j/3][num-1]) continue;
            
            set(i, j, num, 1);
            board[i][j] = '0' + num;

            if (dfs(board, i, j)) return true;

            set(i, j, num, 0);
            board[i][j] = '.';
        }

        return false;
    }

    void set(int i, int j, int num, bool sig) {
        rows[i][num-1] = sig;
        cols[j][num-1] = sig;
        grid[i/3*3+j/3][num-1] = sig;
    }
};

int main() {
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution solu;

    solu.solveSudoku(board);

    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}