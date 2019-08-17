#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 比较巧妙的方法
        // 把数组分为分别包含两个一次数中的一个的子数组
        vector<int> nums1, nums2;
        int x = 0, mask = 1, a = 0, b = 0;
        
        for (int num: nums) x ^= num;
        while ((mask&x) == 0) mask <<= 1;
        
        for (int num: nums) {
            if (num&mask) a ^= num;
            else b ^= num;
        }
        
        return vector<int>{a, b};
    }
};