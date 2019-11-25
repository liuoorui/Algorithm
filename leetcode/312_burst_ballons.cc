class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        size_t n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (size_t len = 2; len < n; ++len) {
            for (size_t i = 0; i < n - len; ++i) {
                size_t j = i + len;
                for (size_t k = i + 1; k < j; ++k)
                    dp[i][j] = max(dp[i][j], nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j]);
            }
        }
        return dp[0][n - 1];
    }
};
