class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> set;
        memset(set.data(), 0, set.size() * sizeof(int));
        
        for (auto ch : s) {
            ++set[ch - 'a'];
        }
        
        for (auto ch : t) {
            if (--set[ch - 'a'] < 0)
                return false;
        }
        
        return true;
    }
};
