#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray1(vector<int>& nums) {
        // 扫描算法
        int maxSum = INT_MIN, currSum = 0, i = 0;
        
        while (i < nums.size()) {
            currSum += nums[i++];
            maxSum = max(maxSum, currSum);
            
            if (currSum < 0) currSum = 0;
        }
        
        return maxSum;
    }
    int maxSubArray2(vector<int>& nums) {
        // 分治算法
        return maxSubArray(&nums[0], 0, nums.size());
    }
private:
    int maxSubArray(int* nums, int beg, int end) {
        if (beg >= end) return 0x80000000;
        int mid = beg+(end-beg)/2, maxSum = 0x80000000, currSum = 0;
        
        for (int i=mid; i>=beg; --i) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
        }
        currSum = maxSum;
        for (int i=mid+1; i<end; ++i) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
        }
        
        return max(maxSum, max(maxSubArray(nums, beg, mid), 
                               maxSubArray(nums, mid+1, end)));
    }
};