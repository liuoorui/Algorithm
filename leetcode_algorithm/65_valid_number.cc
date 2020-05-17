#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        // 按照'e', '.'划分
        // 先实现出来了, 有点啰嗦，有空再优化代码
        int i = 0, j = 0, k = s.size()-1;
        string left_e = "", right_e = "";
        
        while (i<s.size() && s[i]==' ') ++i;
        j = i;
        while (k>=0 && s[k]==' ') --k;
        ++k;
        while (j<k && s[j]!='e') ++j;
        
        if (j == k) return isNum(s.substr(i, k-i));
        
        if (i < j) left_e = s.substr(i, j-i);
        if (j < k-1) right_e = s.substr(j+1, k-j-1);
        
        if (left_e.empty() || right_e.empty()) return false;
        return isNum(left_e) && isInteger(right_e);
    }
private:
    bool isNum(string s) {
        if (s.empty()) return false;
        int i = 0, j = 0;
        string left = "", right = "";
        
        if (s[0]=='+' || s[0]=='-') ++i;
        j = i;
        
        while (j<s.size() && s[j]!='.') ++j;
        
        if (j == s.size()) return isInteger(s);
        
        if (i < j) left = s.substr(i, j-i);
        if (j < s.size()-1) right = s.substr(j+1);
        
        if (left.empty() && right.empty()) return false;
        
        return isPostiveInteger(left) && isPostiveInteger(right);
    }
    bool isInteger(string s) {
        if (s.empty()) return false;
        int i = 0;
        
        if (s[i]=='+' || s[i]=='-') ++i;
        s = s.substr(i);
        return !s.empty() && isPostiveInteger(s);
    }
    bool isPostiveInteger(string s) {
        for (char ch: s)
            if (!isdigit(ch)) return false;
        return true;
    }
};