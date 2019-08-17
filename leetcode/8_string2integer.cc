#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool sign = 0;
        int num = 0, idx = 0;

        while (str[idx] == ' ') ++idx;
        cout<<"idx = "<<idx<<endl;
        if (str[idx] == '-') {
            sign = 1;
            ++idx;
        } else if (str[idx] == '+') {
            ++idx;
        }

        while (idx<str.size() && isdigit(str[idx])) {
            // cout<<"idx = "<<idx<<" num = "<<num<<endl;
            int x = str[idx++] - '0';
            if (sign) {
                if (num>INT_MAX/10 || (num==INT_MAX/10 && x>8)) 
                    return INT_MIN;
            } else {
                if (num>INT_MAX/10 || (num==INT_MAX/10 && x>7))
                    return INT_MAX;
            }

            num = num * 10 + x;
        }

        return sign? -num: num;
    }
};

int main () {
    int n, res;
    string str = "";
    char ch;
    Solution solu;

    cout<<"input string length: ";
    cin>>n;
    cout<<"input string: ";
    cin.sync();
    cin.ignore();
    while (n--) {
        cin.get(ch);
        str.push_back(ch);
    }

    cout<<str<<endl;
    res = solu.myAtoi(str);

    cout<<res<<endl;
}