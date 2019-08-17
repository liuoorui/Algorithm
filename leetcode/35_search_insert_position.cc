#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = nums.size();
        
        while (beg < end) {
            int mid = beg + (end-beg)/2;
            
            if (nums[mid] < target) beg = mid + 1;
            else end = mid;
        }
        
        return beg;
    }
};

