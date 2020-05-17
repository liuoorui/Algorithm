#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // 二维动态规划，可以优化到一维
        // leetcode有个test case过不了，应该是test case结果太大超过整型范围的原因 
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        dp[0][0] = 1;
        
        for (int i=1; i<=s.size(); ++i)
            for (int j=0; j<=t.size(); ++j) {
                if (j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
                
                // cout<<dp[i][j]<<" ";
                // if (j == t.size()) cout<<endl;
            }
        
        return dp.back().back();
    }
};