#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size()-1, j = b.size()-1, carry = 0;
        
        while (i>=0 && j>=0) {
            int num = (a[i--]-'0') + (b[j--]-'0') + carry;
            res.push_back('0'+num%2);
            carry = num / 2;
        }
        
        if (i < 0) {
            i = j;
            a = b;
        }
        
        while (i >= 0 ) {
            int num = (a[i--]-'0') + carry;
            res.push_back('0'+num%2);
            carry = num / 2;
        }
        if (carry) res.push_back('1');
        
        i = 0, j = res.size()-1;
        while (i < j) swap(res[i++], res[j--]);
        
        return res;
    }
};