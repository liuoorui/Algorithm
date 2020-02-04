// 累加数是一个字符串，组成它的数字可以形成累加序列。
// 
// 一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
// 
// 给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
// 
// 说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
// 
// 示例 1:
// 
// 输入: "112358"
// 输出: true 
// 解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// 示例 2:
// 
// 输入: "199100199"
// 输出: true 
// 解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
// 进阶:
// 你如何处理一个溢出的过大的整数输入?
// 
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/additive-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        for (size_t i = 1; i < num.size() - 1; ++i) {
            for (size_t j = i + 1; j <= num.size() / 3 * 2; ++j) {
                string a = num.substr(0, i);
                string b = num.substr(i, j - i);
                if (a[0] == '0' && a.size() > 1 || 
                    b[0] == '0' && b.size() > 1) continue;
                if (isAdditiveNumber(num, j, a, b)) return true;
            }
        }
        
        return false;
    }
private:
    inline bool isAdditiveNumber(const string &num, 
                                 size_t idx, 
                                 string a, string b) {
        if (idx >= num.size()) return false;
        
        while (idx < num.size()) {
            string c = addStr(a, b);
            size_t len = c.size();
            
            if (idx + len > num.size()) return false;
            for (size_t i = 0; i < len; ++i) {
                if (num[idx + i] != c[i]) return false;
            }
            
            a.swap(b);
            b.swap(c);
            idx += len;
        }
        
        return true;
    }
    
    inline string addStr(const string &a, const string &b) {
        int idx_a = a.size() - 1; // size_t -> int.
        int idx_b = b.size() - 1;
        string c;
        int carry = 0;
        
        while (idx_a >= 0 || idx_b >= 0) {
            int num = carry;
            if (idx_a >= 0) num += a[idx_a--] - '0';
            if (idx_b >= 0) num += b[idx_b--] - '0';
            
            c.push_back('0' + (num % 10));
            carry = num / 10;
        }
        if (carry) c.push_back('0' + carry);
        
        reverse(c.begin(), c.end());
        return c;
    }
};
