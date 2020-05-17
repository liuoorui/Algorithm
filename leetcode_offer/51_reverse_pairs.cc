// 面试题51. 数组中的逆序对
// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
// 
//  
// 
// 示例 1:
// 
// 输入: [7,5,6,4]
// 输出: 5
//  
// 
// 限制：
// 
// 0 <= 数组长度 <= 50000

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return merge(nums, temp, 0, nums.size());
    }
private:
    int merge(vector<int> &nums, vector<int> &temp, int beg, int end) {
        if (end - beg <= 1) return 0;
        int cnt = 0, mid = beg + (end - beg) / 2;
        cnt += merge(nums, temp, beg, mid);
        cnt += merge(nums, temp, mid, end);
        
        int l = beg, r = mid, idx = 0;
        while (l < mid || r < end) {
            int next = INT_MIN;
            if (l < mid && nums[l] >= next) next = nums[l];
            if (r < end && nums[r] >= next) next = nums[r];
            
            temp[idx++] = next;
            if (r < end && next == nums[r]) {
                ++r;
            } else {
                cnt += end - r;
                ++l;
            }
        }
        
        idx = beg;
        for (int i = 0; i < end - beg; ++i) nums[idx + i] = temp[i];
        return cnt;
    }
};
