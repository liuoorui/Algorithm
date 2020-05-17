class Solution {
public:
    string shortestPalindrome(string s) {
        // 转化成kmp查找 s + rev 的最长前缀的问题。
        auto rev = s;
        reverse(rev.begin(), rev.end());
        auto new_s = s + "*" + rev;
        vector<int> nexts(new_s.size(), 0);
        
        for (size_t i = 1; i < nexts.size(); ++i) {
            int t = nexts[i - 1];
            while (t > 0 && new_s[t] != new_s[i])
                t = nexts[t - 1];
            if (new_s[t] == new_s[i]) ++t;
            nexts[i] = t;
        }
        
        return rev.substr(0, s.size() - nexts.back()) + s;
    }
};
