#include <iostream>
#include <vector>

class Solution {
public:
//	int missingNumber(vector<int>& nums) {
//        // 用 -1 标志空的位置。
//        int ans = -1;
//        nums.push_back(-1);
//        
//        for (int i = 0; i < nums.size(); ++i) {
//            if (i == nums[i]) continue;
//            int idx = nums[i];
//            nums[i] = -1;
//            
//            while (idx != -1 && idx != nums[idx]) {
//                int next = nums[idx];
//                nums[idx] = idx;
//                idx = next;
//            }
//        }
//        for (int i = 0; i < nums.size(); ++i) {
//            if (i != nums[i]) {
//                ans = i;
//                break;
//            }
//        }
//        return ans;
//    }

	int missingNumber(vector<int>& nums) {
        int res = nums.size();
       
        for (int i = 0; i < nums.size(); ++i) {
            res ^= nums[i] ^ i;
        }
        
        return res;
    }
};
