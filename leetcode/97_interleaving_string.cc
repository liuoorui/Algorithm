#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m+n != s3.size()) return false;
        bool dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        // vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        
        for (int i=1; i<=m; ++i) {
            if (s1[i-1] != s3[i-1]) break;
            dp[i][0] = true;
        }
        for (int j=1; j<=n; ++j) {
            if (s2[j-1] != s3[j-1]) break;
            dp[0][j] = true;
        }
        
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if ((s1[i-1]==s3[i+j-1] && dp[i-1][j]) || 
                    (s2[j-1]==s3[i+j-1] && dp[i][j-1]))
                    dp[i][j] = true;
            }
        }
        
        return dp[m][n];
    }
};