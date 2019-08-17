#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> rows(9);
        vector<bitset<9>> cols(9);
        vector<bitset<9>> grid(9);
        
        for (int i=0; i<9; ++i)
            for (int j=0; j<9; ++j) {
                if (board[i][j] == '.') continue;
                int idx = board[i][j] - '1';
                
                if (rows[i][idx] == 1) return false;
                else rows[i][idx] = 1;
                
                if (cols[j][idx] == 1) return false;
                else cols[j][idx] = 1;
                
                if (grid[i/3*3+j/3][idx] == 1) return false;
                else grid[i/3*3+j/3][idx] = 1;
            }
        
        return true;
    }
};

int main() {
    Solution solu;
    vector<vector<char>> board(9, vector<char>(9));
    bool res;

    cout<<"Input: "<<endl;
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cin>>board[i][j];
        }
    }
    cout<<"sudoku: "<<endl;
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    res = solu.isValidSudoku(board);
    cout<<res<<endl;
}