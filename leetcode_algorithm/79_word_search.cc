#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return word.empty();
        
        for (int i=0; i<board.size(); ++i)
            for (int j=0; j<board[0].size(); ++j)
                if (dfs(board, word, 0, i, j)) return true;
        
        return false;
    }
private:
    int next[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(vector<vector<char>>& board, string& word, 
             int idx, int i, int j) {
        if (idx == word.size()) return true;
        if (i<0 || i>=board.size() || 
            j<0 || j>=board[0].size()) return false;
        if (word[idx] != board[i][j]) return false;
        
        char temp = board[i][j];
        board[i][j] = '*';
        for (int k=0; k<4; ++k) {
            if (dfs(board, word, idx+1, i+next[k][0], j+next[k][1]))
                return true;
        }
        board[i][j] = temp;
        
        return false;
    }
};