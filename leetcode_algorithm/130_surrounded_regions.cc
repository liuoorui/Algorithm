#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        
        for (int j=0; j<n; ++j) {
            if (board[0][j] == 'O') 
                dfs(board, 0, j);
            if (board[m-1][j] == 'O')
                dfs(board, m-1, j);
        }
        
        for (int i=1; i<m-1; ++i) {
            if (board[i][0] == 'O') 
                dfs(board, i, 0);
            if (board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }
        
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                if (board[i][j] == '*')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board[0].size();
        
        if (i<0 || i>=m || j<0 || j>=n) return;
        if (board[i][j] != 'O') return;
        
        board[i][j] = '*';
        
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
};