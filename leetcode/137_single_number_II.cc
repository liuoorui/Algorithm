#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // k, p 问题
        
        int a = 0, b = 0;
        
        for (int num: nums) {
            // 对num为1的位， 计数器加一
            a ^= b & num;
            b ^= num;
            
            // 对计数为k的置0, k=11;
            int mask = ~(a & b);
            a &= mask;
            b &= mask;
        }
        
        return b;
    }
};