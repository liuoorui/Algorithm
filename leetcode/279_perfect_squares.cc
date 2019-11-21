class Solution {
public:
//     int numSquares(int n) {
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0;
        
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j * j <= i; ++j) {
//                 dp[i] = min(dp[i], dp[i - j * j] + 1);
//             }
//         }
        
//         return dp[n];
//     }
    
    int numSquares(int n) {
        // if n == 4^a(8b + 7), return 4;
        // else return 1/2/3;
        
        // return 4.
        while (0 == n % 4) n /= 4;
        if (7 == n % 8) return 4;
        
        // return 1 / 2.
        for (int i = 0; i * i < n; ++i) {
            int j = sqrt(n - i * i);
            if (i * i + j * j == n) return !!i + !!j;
        }
        
        // return 3.
        return 3;
    }
};
