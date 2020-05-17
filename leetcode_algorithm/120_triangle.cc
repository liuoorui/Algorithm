#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 由于用过的dp可以不再使用
        // 因此可以将m*n的dp空间优化到n；
        vector<int> dp = triangle.back();
        
        for (int i=triangle.size()-1; i>=0; --i) {
            for (int j=0; j<i; ++j)
                dp[j] = min(dp[j], dp[j+1]) + triangle[i-1][j];
        }
        
        return dp[0];
    }
};