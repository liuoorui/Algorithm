// 266. 回文排列
// 给定一个字符串，判断该字符串中是否可以通过重新排列组合，形成一个回文字符串。
// 
// 示例 1：
// 
// 输入: "code"
// 输出: false
// 示例 2：
// 
// 输入: "aab"
// 输出: true
// 示例 3：
// 
// 输入: "carerac"
// 输出: true

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> count;
        int odd_cnt = 0;
        
        for (auto ch : s) count[ch]++;
        for (auto &elem : count) {
            if (elem.second % 2 != 0) ++odd_cnt;
        }
        
        return (s.size() % 2 == 0 && odd_cnt == 0)
            || (s.size() % 2 != 0 && odd_cnt == 1);
    }
};