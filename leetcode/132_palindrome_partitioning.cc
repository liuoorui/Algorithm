#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        vector<int> ans(n+1, 0x7fffffff);
        ans[0] = -1;
        
        for (int i=n-1; i>=0; --i) 
            for (int j=i; j<n; ++j) {
                if (i == j) dp[i][j] = true;
                else dp[i][j] = s[i]==s[j] && dp[i+1][j-1];
            }

        for (int j=0; j<n; ++j)
            for (int i=j; i>=0; --i) {
                if (dp[i][j])
                    ans[j+1] = min(ans[j+1], ans[i]+1);
            }

        return ans.back();
    }
};