#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // *能匹配所有形式字符串
        // 有推论：只需回溯前一个*
        // 同样也可以用动态规划来做
        int m = s.size(), n = p.size(), 
            i = 0, j = 0, pre_i = 0, pre_j = 0;
        bool hasStar = false;
        
        while (i < m) {
            if (j<n && p[j] == '*') {
                hasStar = true;
                while (j<n && p[j]=='*') ++j;
                if (j == n) return true;
                
                pre_i = i;
                pre_j = j;
            } else if (j>=n || (j<n && (s[i]!=p[j] && p[j]!='?'))) {
                if (hasStar) {
                    ++pre_i;
                    i = pre_i;
                    j = pre_j;
                } else {
                    return false;
                }
            } else {
                ++i; ++j;
            }
        }
        
        while (j<n && p[j]=='*') ++j;
        return j == n;
    }
};