#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 每层依次变换
        // 或者可以先对角变换再镜像，但是就需要变换两次
        int beg_i = 0, beg_j = 0, 
            end_i = matrix.size()-1, end_j = end_i;
        
        while (beg_i < end_i) {
            rotate(matrix, beg_i, beg_j, end_i, end_j);
            
            ++beg_i;
            ++beg_j;
            --end_i;
            --end_j;
        }
    }
private:
    void rotate(vector<vector<int>>& matrix, int beg_i, int beg_j,
               int end_i, int end_j) {
        int k = 0, temp;
        
        while (k < end_i-beg_i) {
            temp = matrix[beg_i][beg_j+k];
            
            matrix[beg_i][beg_j+k] = matrix[end_i-k][beg_j];
            matrix[end_i-k][beg_j] = matrix[end_i][end_j-k];
            matrix[end_i][end_j-k] = matrix[beg_i+k][end_j];
            matrix[beg_i+k][end_j] = temp;
            
            ++k;
        }
    }
};