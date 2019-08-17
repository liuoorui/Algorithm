#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public: 
    int divide(int dividend, int divisor) {
        if (dividend==INT_MIN && divisor==-1) return INT_MAX;
        bool sign = (dividend^divisor) < 0;
        uint32_t rem = abs(dividend);
        uint32_t div = abs(divisor);
        if (rem < div) return 0;

        int quot = 1;

        while (1) {
            if (div > INT_MAX/2) break;
            if (div > rem/2) break;

            div <<= 1;
            quot <<=1;
        }

        quot += divide(rem-div, abs(divisor));
        return sign? -quot: quot;
    }
};

int main() {
    Solution solu;
    int dividend, divisor, quot;

    cout<<"Input dividend and divisor: ";
    cin>>dividend>>divisor;

    quot = solu.divide(dividend, divisor);

    cout<<quot<<endl;
}