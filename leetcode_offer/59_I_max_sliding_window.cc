// 面试题59 - I. 滑动窗口的最大值
// 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
// 
// 示例:
// 
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7] 
// 解释: 
// 
//   滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//  
// 
// 提示：
// 
// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
// 
// 注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> win;
        vector<int> ans;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i >= k && win.front() == nums[i - k])
                win.pop_front();
            while (!win.empty() && win.back() < nums[i])
                win.pop_back();
            win.push_back(nums[i]);
            
            if (i >= k - 1) 
                ans.push_back(win.front());
        }
        return ans;
    }
};
