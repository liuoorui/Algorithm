class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        uint32_t p = 0xffffffff;
        
        while (m != n) {
            p <<= 1;
            m &= p;
            n &= p;
        }
        
        return m;
    }
};
