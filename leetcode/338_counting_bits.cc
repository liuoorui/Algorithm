class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        int beg = 0, next = 1, idx = 1;
        
        while (idx <= num) {
            if (idx == next) {
                beg = 0;
                next <<= 1;
            }
            
            ans[idx++] = an[beg++] + 1;
        }
        
        return ans;
    }
};
