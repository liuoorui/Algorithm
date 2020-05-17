class Solution {
public:
    int countSubstrings(string s) {
        int cnt = s.size();
        vector<int> dp(s.size(), 1);
        
        for (size_t i = 0; i < s.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (s[j] == s[i] && dp[j + 1] == 1) {
                    ++cnt;
                    dp[j] = 1;
                } else {
                    dp[j] = 0;
                }
            }
        }
        
        return cnt;
    }
};
