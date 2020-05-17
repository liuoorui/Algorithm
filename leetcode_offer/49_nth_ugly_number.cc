// 面试题49. 丑数
// 我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
// 
//  
// 
// 示例:
// 
// 输入: n = 10
// 输出: 12
// 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
// 说明:  
// 
// 1 是丑数。
// n 不超过1690。
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/
// 
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        size_t idx_2 = 0, idx_3 = 0, idx_5 = 0;
        
        for (size_t i = 1; i < n; ++i) {
            int next = min(ugly[idx_2] * 2, 
                           min(ugly[idx_3] * 3, ugly[idx_5] * 5));
            ugly[i] = next;
            
            if (ugly[idx_2] * 2 == next) ++idx_2;
            if (ugly[idx_3] * 3 == next) ++idx_3;
            if (ugly[idx_5] * 5 == next) ++idx_5;
        }
        
        return ugly.back();
    }
};
