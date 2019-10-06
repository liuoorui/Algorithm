#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 方法一，二分筛选。
        int first = 1;
        int last = nums.size() - 1;
        
        while (first < last) {
            int mid = first + (last - first) / 2;
            int cnt = std::count_if(nums.cbegin(), nums.cend(), 
                                   [mid](int num) { return num <= mid; });
            
            if (cnt <= mid) first = mid + 1;
            else last = mid;
        }
        
        return first;
    }

    int findDuplicate2(vector<int>& nums) {
        // 方法二，相当于寻找环的入口地址。
        int slow = 0;
        int fast = 0;
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (slow != fast);
        
        return fast;
    }
};