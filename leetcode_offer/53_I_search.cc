// 面试题53 - I. 在排序数组中查找数字 I
// 统计一个数字在排序数组中出现的次数。
// 
//  
// 
// 示例 1:
// 
// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: 2
// 示例 2:
// 
// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: 0
//  
// 
// 限制：
// 
// 0 <= 数组长度 <= 50000
// 
//  
// 
// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return my_upper_bound(nums.data(), nums.data() + nums.size(), target) - 
               my_lower_bound(nums.data(), nums.data() + nums.size(), target);
    }
private:
    const int* my_lower_bound(const int *beg, const int *end, int target) {
        auto l = beg, r = end;
        
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (*mid < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    
    const int* my_upper_bound(const int *beg, const int *end, int target) {
        auto l = beg, r = end;
        
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (*mid > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
