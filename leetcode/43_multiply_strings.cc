#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        const int leng1 = num1.size(), leng2 = num2.size(), 
            leng = leng1 + leng2;
        int n1[leng1], n2[leng2], n[leng];
        int i = leng1 - 1, j = leng2 - 1, carry = 0;
        string res = "";
        memset(n1, 0, sizeof(n1));
        memset(n2, 0, sizeof(n2));
        memset(n, 0, sizeof(n));
        
        for (char ch: num1) n1[i--] = ch - '0';
        for (char ch: num2) n2[j--] = ch - '0';
        
        for (i=0; i<leng1; ++i)
            for (j=0; j<leng2; ++j) {
                n[i+j] += n1[i] * n2[j];
            }
        
        for (int num: n) {
            res = to_string((num+carry)%10) + res;
            carry = (num+carry)/10;
        }
        while (carry) {
            res = to_string(carry%10) + res;
            carry /= 10;
        }
        
        i = 0;
        while (i<res.size()-1 && res[i]=='0') ++i;
        
        return res.substr(i);
    }
};