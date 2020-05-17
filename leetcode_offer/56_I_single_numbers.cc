// 面试题56 - I. 数组中数字出现的次数
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
// 
//  
// 
// 示例 1：
// 
// 输入：nums = [4,1,4,6]
// 输出：[1,6] 或 [6,1]
// 示例 2：
// 
// 输入：nums = [1,2,10,4,1,4,3,3]
// 输出：[2,10] 或 [10,2]
//  
// 
// 限制：
// 
// 2 <= nums <= 10000

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int p = 0;
        for (auto num : nums) p ^= num;
        p = p & (-p);
        
        vector<int> ans(2, 0);
        for (auto num : nums) {
            if (num & p) ans[0] ^= num;
            else ans[1] ^= num;
        }
        return ans;
    }
};
