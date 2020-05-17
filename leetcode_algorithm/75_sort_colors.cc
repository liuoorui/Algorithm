#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = -1, r = nums.size(), idx = 0;
        
        while (idx < r) {
            if (nums[idx] == 0) swap(nums[++l], nums[idx++]);
            else if (nums[idx] == 2) swap(nums[--r], nums[idx]);
            else ++idx;
        }
    }
};