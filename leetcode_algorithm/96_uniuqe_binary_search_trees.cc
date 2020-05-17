#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1] = {0};
        dp[0] = 1;
        
        for (int i=1; i<=n; ++i) {
            for (int k=0; k<i; ++k)
                dp[i] += dp[k] * dp[i-1-k];
        }
        
        return dp[n];
    }
};