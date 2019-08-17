#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle1(vector<vector<char>>& matrix) {
        // 动态规划
        // 保存当前行中每个元素的左右边界
        if (matrix.empty() || matrix[0].empty()) return 0;
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0), left(n, 0), right(n, n);
        int max_aera = 0, curr_aera;
        
        for (int i=0; i<m; ++i) {
            int curr_left = 0, curr_right = n;
            
            for (int j=0; j<n; ++j) {
                heights[j] = matrix[i][j]=='0'? 0: heights[j] + 1;
                
                if (heights[j] > 0) {
                    left[j] = max(left[j], curr_left);
                } else {
                    curr_left = j + 1;
                    left[j] = 0;
                }
            }
            
            for (int j=n-1; j>=0; --j) {
                if (heights[j] > 0) {
                    right[j] = min(right[j], curr_right);
                } else {
                    curr_right = j;
                    right[j] = n;
                }
            }
            
            for (int j=0; j<n; ++j) {
                curr_aera = heights[j] * (right[j] - left[j]);
                max_aera = max(max_aera, curr_aera);
            }
        }
        
        return max_aera;
    }

    int maximalRectangle2(vector<vector<char>>& matrix) {
        // 递增栈解法
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), max_aera = 0, curr_aera;
        vector<int> heights(n+1, 0);
        
        for (int i=0; i<m; ++i) {
            stack<int> s;
            
            for (int j=0; j<n; ++j)
                heights[j] = matrix[i][j]=='0'? 0: heights[j] + 1;
            
            for (int j=0; j<=n; ) {
                if (s.empty() || heights[s.top()]<=heights[j]) {
                    s.push(j++);
                } else {
                    int idx = s.top();
                    s.pop();
                    
                    curr_aera = heights[idx] * (s.empty()?j: j-s.top()-1);
                    max_aera = max(max_aera, curr_aera);
                }
            }
        }
        
        return max_aera;
    }
};