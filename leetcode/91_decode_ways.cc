#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0]=='0') return 0;
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i=1; i<n; ++i) {
            if (s[i] == '0') {
                if (s[i-1]=='1' || s[i-1]=='2')
                    dp[i+1] = dp[i-1];
                else 
                    // 未能解码
                    return 0;
            } else {
                int num = atoi(s.substr(i-1, 2).c_str());  
                dp[i+1] = dp[i];
                
                if (s[i-1]!='0' && num<=26)
                    dp[i+1] += dp[i-1];
            }
        }
        
        return dp[n];
    }
};