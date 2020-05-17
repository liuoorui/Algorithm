class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(rob(nums.data(), nums.size() - 1), 
                   rob(nums.data() + 1, nums.size() - 1));
    }
private:
    int rob(const int* nums, int size) {
        if (size == 1) return *nums;
        vector<int> dp(size + 1);
        dp[1] = *nums;
        
        for (int i = 1; i < size; ++i) {
            dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
        }
        return dp[size];
    }
};
