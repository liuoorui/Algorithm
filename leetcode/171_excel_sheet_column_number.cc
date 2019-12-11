class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        
        for (const auto ch : s) {
            ans *= 26;
            ans += ch - 'A' + 1;
        }
        
        return ans;
    }
};
