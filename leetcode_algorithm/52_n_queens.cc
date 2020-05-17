#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<string> board(n, string(n, '.'));
        dfs(res, board, n, 0, 0);
        
        return res;
    }
private:
    bitset<1000> cols, lDiag, rDiag;
    void dfs(int& res, vector<string>& board, 
             int n, int i, int cnt) {
        if (i == n) {
            if (cnt == n)
                ++res;
            return;
        }
        
        for (int j=0; j<n; ++j) {
            if (cols[j] || lDiag[i+j] || rDiag[i+(n-1-j)])
                continue;
            cols[j] = 1;
            lDiag[i+j] = 1;
            rDiag[i+(n-1-j)] = 1;
            board[i][j] = 'Q';
            
            dfs(res, board, n, i+1, cnt+1);
            
            cols[j] = 0;
            lDiag[i+j] = 0;
            rDiag[i+(n-1-j)] = 0;
            board[i][j] = '.';
        }
    }
};