// 面试题46. 把数字翻译成字符串
// 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
// 
//  
// 
// 示例 1:
// 
// 输入: 12258
// 输出: 5
// 解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
//  
// 
// 提示：
// 
// 0 <= num < 231

class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        vector<int> dp(str.size() + 1);
        dp[0] = 1;
        dp[1] = 1;
        
        for (size_t i = 2; i < dp.size(); ++i) {
            dp[i] = dp[i - 1];
            
            auto num = stoi(str.substr(i - 2, 2));
            if (num >= 10 && num <= 25)
                dp[i] += dp[i - 2];
        }
        return dp.back();
    }
};
