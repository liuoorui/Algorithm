#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0x7FFFFFFF));
        dp[0][1] = 0;
        
        for (int i=0; i<m; ++i) 
            for (int j=0; j<n; ++j)
                dp[i+1][j+1] = grid[i][j] + 
                    min(dp[i][j+1], dp[i+1][j]);
        
        return dp[m][n];
    }
};