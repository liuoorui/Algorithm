class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        x ^= y;
        while (x) {
            ++ans;
            x &= x - 1;
        }
        
        return ans;
    }
};
