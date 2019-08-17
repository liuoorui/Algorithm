#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int i = 0, j = 1;
        
        while (j < nums.size()) {
            if (nums[i]==nums[j] && (i>0 && nums[i]==nums[i-1]))
                ++j;
            else
                nums[++i] = nums[j++];
        }
        
        return i+1;
    }
};