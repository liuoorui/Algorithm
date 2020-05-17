class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0; // 相当于两位二进制 ab。
        int mask = 0, carry = 0;
        
        for (auto num : nums) {
            carry = b & num;
            b ^= num;
            a ^= carry;
            
            // 11 -> 00
            mask = a & b;
            a ^= mask;
            b ^= mask;
        }
        return b;
    }
};
