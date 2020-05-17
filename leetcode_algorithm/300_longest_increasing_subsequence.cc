class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 维护一个最长子序列长度的列表。O(nlogn)。
        vector<int> lis;
        
        for (int num : nums) {
            size_t pos = lower_bound(lis.begin(), lis.end(), num) 
                         - lis.begin();
            if (pos == lis.size()) lis.push_back(num);
            else lis[pos] = num;
        }
        
        return lis.size();
    }
    
//     int lengthOfLIS(vector<int>& nums) {
//         // 动态规划，O(n^2).
//         int ans = 0;
//         vector<int> dp(nums.size(), 1);
        
//         for (size_t i = 0; i < nums.size(); ++i) {
//             for (size_t j = 0; j < i; ++j) {
//                 if (nums[i] > nums[j])
//                     dp[i] = max(dp[i], dp[j] + 1);
//             }
//             ans = max(ans, dp[i]);
//         }
        
//         return ans;
//     }
};
