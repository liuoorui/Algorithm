#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 看作一维数组，直接二分查找。16ms
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size(), 
            beg = 0, end = m*n, mid;
        
        while (beg < end) {
            mid = beg + (end-beg)/2;
            int curr = matrix[mid/n][mid%n];
            
            if (curr < target) beg = mid + 1;
            else if (curr > target) end = mid;
            else return true;
        }
        
        return false;
    }

    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        // 两遍二分查找，16ms
        if (matrix.empty() || matrix[0].empty()) return false;
        int idx, beg = 0, end = matrix.size(), mid;
        while (beg < end) {
            mid = beg + (end-beg)/2;
            
            if (matrix[mid][0] < target) beg = mid + 1;
            else if (matrix[mid][0] > target) end = mid;
            else return true;
        }
        idx = beg;
        --idx;
        if (idx < 0) return false;
        
        beg = 0, end = matrix[0].size();
        while (beg < end) {
            mid = beg + (end-beg)/2;
            
            if (matrix[idx][mid] > target) end = mid;
            else if (matrix[idx][mid] < target) beg = mid + 1;
            else return true;
        }
        
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        // O(m+n), 20ms;
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size(), i = m-1, j = 0;
        
        while (i>=0 && j<n) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) ++j;
            else --i;
        }
        
        return false;
    }
};