#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return fast;
    }
};