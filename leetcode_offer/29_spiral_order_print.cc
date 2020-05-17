// 面试题29. 顺时针打印矩阵
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
// 
//  
// 
// 示例 1：
// 
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 示例 2：
// 
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
//  
// 
// 限制：
// 
// 0 <= matrix.length <= 100
// 0 <= matrix[i].length <= 100
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>();
        int row_beg = 0, row_end = matrix.size();
        int col_beg = 0, col_end = matrix[0].size();
        vector<int> ans(row_end * col_end);
        int loop_tag = 0, idx = 0;
        
        while (row_beg < row_end && col_beg < col_end) {
            if (loop_tag == 0) {
                for (int j = col_beg; j < col_end; ++j)
                    ans[idx++] = matrix[row_beg][j];
                ++row_beg;
            } else if (loop_tag == 1) {
                for (int i = row_beg; i < row_end; ++i)
                    ans[idx++] = matrix[i][col_end - 1];
                --col_end;
            } else if (loop_tag == 2) {
                for (int j = col_end - 1; j >= col_beg; --j)
                    ans[idx++] = matrix[row_end - 1][j];
                --row_end;
            } else {
                for (int i = row_end - 1; i >= row_beg; --i)
                    ans[idx++] = matrix[i][col_beg];
                ++col_beg;
            }
            loop_tag = (loop_tag + 1) % 4;
        }
        
        return ans;
    }
};
