#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, *dp;
        dp = (int*) malloc(s.size()*sizeof(int));
        
        for (int i=0; i<s.size(); ++i) {
            dp[i] = 0;
            int beg = i-1-dp[i-1];
            if (s[i]==')' && i>0 && s[beg]=='(') {
                dp[i] = dp[i-1] + 2 + (beg>0? dp[beg-1]: 0);
                res = max(res, dp[i]);
            }
        }
        
        return res;
    }
}