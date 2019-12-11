class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        // 记录每个char上一次出现的位置。
        vector<int> s_map(128, -1);
        vector<int> t_map(128, -1);
        
        for (size_t i = 0; i < s.size(); ++i) {
            if (s_map[s[i]] != t_map[t[i]])
                return false;
            
            s_map[s[i]] = i;
            t_map[t[i]] = i;
        }
        
        return true;
    }
};
