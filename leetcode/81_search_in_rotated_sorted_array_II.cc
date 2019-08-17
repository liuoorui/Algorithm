#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int l = 0, r = nums.size()-1, m;
        
        while (l <= r) {
            while (l<r && nums[l]==nums[r]) ++l;
            while (r>l && nums[r]==nums[r-1]) --r;
            m = l + (r-l)/2;
            
            if (nums[m] == target) return true;
            
            if (nums[m] < nums[r]) {//右边有序
                if (target>nums[r] || target<nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {//左边有序
                if (target>nums[m] || target<nums[l])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        
        return false;
    }
};