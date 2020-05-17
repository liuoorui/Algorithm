class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int max_length = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int dp[rows + 1][cols + 1];// 存放以该点为右下角的正方形边长。
        memset(dp, 0, sizeof dp);
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int matrix_i = i - 1;
                int matrix_j = j - 1;
                if (matrix[matrix_i][matrix_j] == '0') continue;
                
                dp[i][j] = 1;
                int pre_length = dp[i-1][j-1];
                for (int k = 1; k <= pre_length; ++k) {
                    if (matrix[matrix_i-k][matrix_j] == '1' && 
                        matrix[matrix_i][matrix_j-k] == '1')
                        ++dp[i][j];
                    else
                        break;
                }
                max_length = max(max_length, dp[i][j]);
            }
        }
        
        return pow(max_length, 2);
    }
};