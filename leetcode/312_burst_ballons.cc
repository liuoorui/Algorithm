// 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
// 
// 现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
// 
// 求所能获得硬币的最大数量。
// 
// 说明:
// 
// 你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
// 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
// 示例:
// 
// 输入: [3,1,5,8]
// 输出: 167 
// 解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//      coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
// 
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/burst-balloons
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
