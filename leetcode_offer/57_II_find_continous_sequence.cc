// 面试题57 - II. 和为s的连续正数序列
// 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
// 
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
// 
//  
// 
// 示例 1：
// 
// 输入：target = 9
// 输出：[[2,3,4],[4,5]]
// 示例 2：
// 
// 输入：target = 15
// 输出：[[1,2,3,4,5],[4,5,6],[7,8]]
//  
// 
// 限制：
// 
// 1 <= target <= 10^5

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> nums(target - 1);
        int sum = 0;
        size_t beg = 0, end = 0;
        
        for (int i = 0; i < nums.size(); ++i) 
            nums[i] = i + 1;
        
        while (end < nums.size()) {
            sum += nums[end++];
            
            while (sum >= target) {
                if (sum == target)
                    ans.emplace_back(nums.cbegin() + beg, nums.cbegin() + end);
                sum -= nums[beg++];
            }
        }
        
        return ans;
    }
};
