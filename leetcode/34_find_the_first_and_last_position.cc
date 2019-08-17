#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums, 0, nums.size(), target),
            right = left==-1? -1: 
                upper_bound(nums, left, nums.size(), target);
        return vector<int>{left, right};
    }
private:
    // 实际上就是实现<algorithm>中的lower_bound()和upper_bound()函数
    int lower_bound(vector<int>& nums, int beg, int end, int target) {
        if (beg >= end) return -1;
        
        while (beg < end) {
            int mid = beg + (end-beg)/2;
            
            if (nums[mid] < target) beg = mid + 1;
            else end = mid;
        }
        
        return (beg<nums.size() && nums[beg]==target)? 
            beg: -1;
    }
    int upper_bound(vector<int>& nums, int beg, int end, int target) {
        if (beg >= end) return -1;
        
        while (beg < end) {
            int mid = beg + (end-beg)/2;
            
            if (nums[mid] > target) end = mid;
            else beg = mid + 1;
        }
        
        return nums[beg-1]==target? beg-1: -1;
    }
};