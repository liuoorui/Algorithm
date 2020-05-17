// 面试题20. 表示数值的字符串
// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"及"-1E-16"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
// 
//  
// 
// 注意：本题与主站 65 题相同：https://leetcode-cn.com/problems/valid-number/

class Solution {
public:
    bool isNumber(string s) {
        size_t beg = 0, end = s.size();
        while (beg < end && s[beg] == ' ') ++beg;
        while (beg < end && s[end - 1] == ' ') --end;
        s = s.substr(beg, end - beg);
        if (s.empty()) return false;
        
        auto pos = s.find('e');
        if (pos == -1) return isFloat(s);
        
        auto left = s.substr(0, pos);
        auto right = s.substr(pos + 1);
        return isFloat(left) && 
               isInteger(right);
    }
private:
    bool isUnsignedInteger(string s) {
        if (s.empty()) return false;
        size_t idx = 0;
        
        while (idx < s.size() && isdigit(s[idx])) ++idx;
        return idx == s.size();
    }
    
    bool isInteger(string s) {
        if (s.empty()) return false;
        if (s[0] == '+' || s[0] == '-')
            return isUnsignedInteger(s.substr(1));
        else
            return isUnsignedInteger(s);
    }
    
    bool isUnsignedFloat(string s) {
        auto pos = s.find('.');
        if (pos == -1) return isUnsignedInteger(s);
        
        auto left = s.substr(0, pos);
        auto right = s.substr(pos + 1);
        if (left.empty() && right.empty()) return false;
        return (left.empty() || isUnsignedInteger(left)) && 
               (right.empty() || isUnsignedInteger(right));
    }
    
    bool isFloat(string s) {
        if (s.empty()) return false;
        if (s[0] == '+' || s[0] == '-')
            return isUnsignedFloat(s.substr(1));
        else
            return isUnsignedFloat(s);
    }
};
