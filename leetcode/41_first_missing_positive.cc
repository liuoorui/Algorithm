#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 检查排序后元素与下标是否匹配来判断
        // 元素是否存在
        int leng = nums.size(), i = 0;
        
        while (i < leng) {
            if (nums[i]<=0 || nums[i]>leng ||
               nums[i]==i+1) 
                ++i;
            else if (nums[i] == nums[nums[i]-1])
                ++i;
            else 
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for (i=0; i<leng; ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return leng + 1;
    }
};