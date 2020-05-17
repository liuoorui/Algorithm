class Solution {
public:
    string decodeString(string s) {
        return decode(s, 0, s.size());
    }
private:
    string decode(const string& s, size_t beg, size_t end) {
        if (beg >= end) return "";

        size_t num_idx = beg;
        while (num_idx < end && !isdigit(s[num_idx])) ++num_idx;
        if (num_idx == end) return s.substr(beg, end - beg);
        
        size_t left_idx = num_idx;
        while (left_idx < end && s[left_idx] != '[') ++left_idx;
        
        size_t right_idx = left_idx, num_brackets = 0;
        while (right_idx < end) {
            if (s[right_idx] == '[') ++num_brackets;
            else if (s[right_idx] == ']') --num_brackets;
            
            if (num_brackets == 0) break;
            ++right_idx;
        }
        
        int cnt = atoi(s.substr(num_idx, left_idx - num_idx).c_str());
        string str = decode(s, left_idx + 1, right_idx);
        string ans = s.substr(beg, num_idx - beg);
        while (cnt--) ans += str;
        ans += decode(s, right_idx + 1, end);
        
        return ans;
    }
};
