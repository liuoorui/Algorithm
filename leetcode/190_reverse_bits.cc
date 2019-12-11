class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t curr = 0;
        int cnt = 32;
        
        while (cnt--) {
            curr = n & 1;
            n >>= 1;
            
            ans <<= 1;
            ans |= curr;
        }
        
        return ans;
    }
};
