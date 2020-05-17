// 面试题50. 第一个只出现一次的字符
// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
// 
// 示例:
// 
// s = "abaccdeff"
// 返回 "b"
// 
// s = "" 
// 返回 " "
//  
// 
// 限制：
// 
// 0 <= s 的长度 <= 50000

class Solution {
public:
    char firstUniqChar(string s) {
        array<int, 256> cmap;
        memset(cmap.data(), 0, cmap.size() * sizeof(int));
        
        for (auto ch : s) ++cmap[ch];
        for (auto ch : s) {
            if (cmap[ch] == 1) return ch;
        }
        return ' ';
    }
};
