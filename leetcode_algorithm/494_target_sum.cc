class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // 目标和问题转化为子集和问题。
        // 0-1背包问题。
        int target = accumulate(nums.cbegin(), nums.cend(), 0);
        if (target < S) return 0;
        target += S;
        if (target % 2 == 1) return 0;
        
        return findSubSumWays(nums, target>>1);
    }
    
private:
    int findSubSumWays(const vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (auto num : nums) {
            for (int i = target; i >= num; --i)
                dp[i] += dp[i - num];
        }
        return dp[target];
    }
};
