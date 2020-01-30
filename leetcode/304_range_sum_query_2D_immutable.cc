class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int rows = matrix.size(), cols = matrix[0].size();
        sums_.resize(rows + 1, vector<int>(cols + 1, 0));
        
        int sum = 0;
        int row_sum = 0;
        
        for (int i = 1; i <= rows; ++i) {
            row_sum = 0;
            for (int j = 1; j <= cols; ++j) {
                row_sum += matrix[i - 1][j - 1];
                sums_[i][j] = row_sum + sums_[i - 1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums_[row2 + 1][col2 + 1]
            - sums_[row1][col2 + 1]
            - sums_[row2 + 1][col1] 
            + sums_[row1][col1];
    }
private:
    vector<vector<int>> sums_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
