#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool rowFlag = false, colFlag = false;
        
        for (int j=0; j<n; ++j)
            if (matrix[0][j] == 0) {
                rowFlag = true;
                break;
            }
        for (int i=0; i<m; ++i) 
            if (matrix[i][0] == 0) {
                colFlag = true;
                break;
            }
        
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j) {
                if (matrix[i][j] != 0) continue;
                
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        
        for (int i=1; i<m; ++i) {
            if (matrix[i][0] != 0) continue;
            for (int j=1; j<n; ++j)
                matrix[i][j] = 0;
        }
        for (int j=1; j<n; ++j) {
            if (matrix[0][j] != 0) continue;
            for (int i=1; i<m; ++i)
                matrix[i][j] = 0;
        }
        
        if (rowFlag) {
            for (int j=0; j<n; ++j) matrix[0][j] = 0;
        }
        if (colFlag) {
            for (int i=0; i<m; ++i) matrix[i][0] = 0;
        }
    }
};