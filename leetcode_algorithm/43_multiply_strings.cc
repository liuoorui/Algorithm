#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() > num2.size()) num1.swap(num2);
        size_t len1 = num1.size(), len2 = num2.size();
        vector<int> product(len1 + len2);

        // 不处理进位，相乘。
        for (size_t i = 0; i < len1; ++i) {
            int curr1 = num1[len1 - 1 - i] - '0';

            for (size_t j = 0; j < len2; ++j) {
                int curr2 = num2[len2 - 1 - j] - '0';
                product[i + j] += curr1 * curr2;
            }
        }

        // 处理进位。
        int carry = 0;
        for (size_t i = 0; i < product.size(); ++i) {
            product[i] += carry;
            carry = product[i] / 10;
            product[i] %= 10;
        }

        // 转到字符串。
        int idx = product.size() - 1;
        while (idx > 0 && product[idx] == 0) --idx;
        string ans;
        while (idx >= 0) {
            ans.push_back('0' + product[idx--]);
        }
        return ans;
    }
};
