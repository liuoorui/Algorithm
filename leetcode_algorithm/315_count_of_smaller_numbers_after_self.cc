// 315. 计算右侧小于当前元素的个数
// 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
// 
// 示例:
// 
// 输入: [5,2,6,1]
// 输出: [2,1,1,0] 
// 解释:
// 5 的右侧有 2 个更小的元素 (2 和 1).
// 2 的右侧仅有 1 个更小的元素 (1).
// 6 的右侧有 1 个更小的元素 (1).
// 1 的右侧有 0 个更小的元素.

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        vector<Pair> buf(nums.size());
        vector<Pair> pair_nums(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            pair_nums[i] = make_pair(nums[i], i);
        }
        
        mergeSort(pair_nums, 0, nums.size(), buf, ans);
        return ans;
    }
private:
    using Pair = pair<int, int>; // 存放nums值和对应的idx。
    void mergeSort(vector<Pair> &nums, size_t beg, size_t end, 
                   vector<Pair> &buf, vector<int> &ans) {
        if (beg >= end || beg + 1 == end) return;
        size_t mid = beg + (end - beg)/2;
        mergeSort(nums, beg, mid, buf, ans);
        mergeSort(nums, mid, end, buf, ans);
        
        size_t i = beg, j = mid, idx = 0;
        while (i < mid && j < end) {
            if (nums[i].first > nums[j].first) {
                ans[nums[i].second] += end - j;
                buf[idx++] = nums[i++];
            } else {
                buf[idx++] = nums[j++];
            }
        }
        while (i < mid) buf[idx++] = nums[i++];
        while (j < end) buf[idx++] = nums[j++];
        
        i = beg, j = 0;
        while (i < end) nums[i++] = buf[j++];
    }
};
