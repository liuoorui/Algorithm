#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size(), i = m-1, j = 0;
        
        while (i>=0 && j<n) {
            if (matrix[i][j] < target) ++j;
            else if (matrix[i][j] > target) --i;
            else return true;
        }
        
        return false;
    }
};