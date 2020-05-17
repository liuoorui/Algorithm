#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int mx = 0, i = 0;
        
        while (i <= mx) {
            if (i+nums[i] > mx) mx = i+nums[i];
            if (mx >= nums.size()-1) return true;
            
            ++i;
        }
        
        return false;
    }
};