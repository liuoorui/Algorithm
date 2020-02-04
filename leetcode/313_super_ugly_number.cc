// 编写一段程序来查找第 n 个超级丑数。
// 
// 超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。
// 
// 示例:
// 
// 输入: n = 12, primes = [2,7,13,19]
// 输出: 32 
// 解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
// 说明:
// 
// 1 是任何给定 primes 的超级丑数。
//  给定 primes 中的数字以升序排列。
// 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
// 第 n 个超级丑数确保在 32 位有符整数范围内。
// 
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/super-ugly-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idxes(primes.size(), 0);
        vector<int> ugly{ 1 };
        
        while (ugly.size() < n) {
            int next = INT_MAX;
            for (size_t i = 0; i < primes.size(); ++i) {
                next = min(next, primes[i] * ugly[idxes[i]]);
            }
            
            for (size_t i = 0; i < primes.size(); ++i) {
                if (primes[i] * ugly[idxes[i]] == next)
                    ++idxes[i];
            }
            ugly.push_back(next);
        }
        return ugly.back();
    }
};
