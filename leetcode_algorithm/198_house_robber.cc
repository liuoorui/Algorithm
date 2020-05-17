class Solution {
public:
    int rob(vector<int>& nums) {
        int curr_max = 0;
        int pre_max = 0;
        
        int temp;
        for (int num : nums) {
            temp = curr_max;
            curr_max = max(curr_max, pre_max + num);
            pre_max = temp;
        }
        
        return curr_max;
    }
    
//     int rob(vector<int>& nums) {
//         const int cnt = nums.size();
//         if (cnt == 0) return 0;
//         else if (cnt == 1) return nums[0];
//         else if (cnt == 2) return max(nums[0], nums[1]);
        
//         int dp[cnt] = { 0 };
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
//         for (int i = 2; i < cnt; ++i) {
//             dp[i] = max(dp[i - 2] + nums[i], 
//                         dp[i - 1]);
//         }
        
//         return dp[cnt - 1];
//     }
};
```
