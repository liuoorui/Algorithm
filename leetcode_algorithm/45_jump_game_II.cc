#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int far = 0, cnt = 0, reached = 0;
        
        for (int i=0; i<nums.size(); ++i) {
            if (i > reached) {
                ++cnt;
                reached = far;
            }
            far = max(far, i+nums[i]);
        }
        
        return cnt;
    }
};