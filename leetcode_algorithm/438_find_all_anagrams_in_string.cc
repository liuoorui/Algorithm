class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;
        
        int len = p.size();
        int win[26];
        int map[26];
        memset(win, 0, 26 * sizeof(int));
        memset(map, 0, 26 * sizeof(int));
        
        for (size_t i = 0; i < len; ++i) {
            ++win[s[i] - 'a'];
            ++map[p[i] - 'a'];
        }
        if (memcmp(win, map, 26 * sizeof(int)) == 0) ans.push_back(0);
        
        for (size_t i = 1; i <= s.size() - len; ++i) {
            --win[s[i - 1] - 'a'];
            ++win[s[i + len - 1] - 'a'];
            if (memcmp(win, map, 26 * sizeof(int)) == 0) ans.push_back(i);
        }
        
        return ans;
    }
};
