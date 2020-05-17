class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2 == 1) return false;
        
        int target = sum >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (auto num : nums) {
            for (size_t i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[target];
    }
};
