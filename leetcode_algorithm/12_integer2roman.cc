#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m{
            {1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"},
            {10,"X"}, {40,"XL"}, {50,"L"}, {90,"XC"},
            {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"},
            {1000,"M"}
        };
        map<int, string>::iterator iter = m.end();
        string res = "";

        --iter;
        while (iter != m.begin()) {
            if (num < iter->first) {
                --iter;
                continue;
            }

            num -= iter->first;
            res += iter->second;
        }

        while (num--) res += "I";

        return res;
    }
};

int main() {
    Solution solu;
    int num;
    string res;

    cout<<"Convert an integer to roman numeral"<<endl;
    cout<<"Input an integer: ";
    cin>>num;

    res = solu.intToRoman(num);
    cout<<res<<endl;
}