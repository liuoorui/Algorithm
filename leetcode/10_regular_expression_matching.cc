#include <iostream>
#include <string>
using namespace std;

class Solution {
public: 
    bool isMatch(string s, string p) {
        // 动态规划 8ms
        // 遇到‘*’则分为两种情况：
        //  1. p-2与s是否已经匹配
        //  2. p与s-1是否已经匹配
        const int m = s.size(), n = p.size();
        bool dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for (int i=0; i<=m; ++i)
            for (int j=1; j<=n; ++j) {
                if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && 
                        (p[j-2]==s[i-1] || p[j-2]=='.'));
                else
                    dp[i][j] = i && dp[i-1][j-1] && 
                        (p[j-1]==s[i-1] || p[j-1]=='.');
            }
        
        return dp[m][n];
    }
};

int main() {
    Solution solu;
    string s, p;
    bool res;

    cout<<"Input string: ";
    cin>>s;
    cout<<"Input pattern: ";
    cin>>p;

    res = solu.isMatch(s, p);

    cout<<res<<endl;
}