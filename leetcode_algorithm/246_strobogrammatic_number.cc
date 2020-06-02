// 246. 中心对称数
// 中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
// 
// 请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。
// 
// 示例 1:
// 
// 输入:  "69"
// 输出: true
// 示例 2:
// 
// 输入:  "88"
// 输出: true
// 示例 3:
// 
// 输入:  "962"
// 输出: false

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> umap{
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        int l = 0, r = num.size() - 1;
        while (l <= r) {
            if (umap.find(num[l]) != umap.end() 
                && umap[num[l]] == num[r]) {
                ++l;
                --r;
            } else {
                return false;
            }
        }
        return true;
    }
};
