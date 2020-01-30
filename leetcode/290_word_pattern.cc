class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        unordered_set<string> str_set;
        array<string *, 26> str_map;
        size_t beg = 0, end = 0;
        
        memset(str_map.data(), 0, sizeof(string *) * str_map.size());
        while (beg < str.size()) {
            while (beg < str.size() && str[beg] == ' ') ++beg;
            end = beg;
            while (end < str.size() && str[end] != ' ') ++end;
            
            if (beg < end) {
                strs.push_back(str.substr(beg, end - beg));
                beg = end;
            }
        }
        
        if (pattern.size() != strs.size()) return false;
        for (size_t i = 0; i < pattern.size(); ++i) {
            size_t idx = pattern[i] - 'a';
            if (str_map[idx] == nullptr) {
                if (str_set.find(strs[i]) != str_set.end()) 
                    return false;
                str_set.insert(strs[i]);
                str_map[idx] = &strs[i];
            } else if (*str_map[idx] != strs[i]) {
                return false;
            }
        }
        
        return true;
    }
};
