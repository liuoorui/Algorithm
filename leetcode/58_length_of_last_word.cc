#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int res = 0;
        char *idx = &s.back(), *beg = &s[0];

        while (idx>=beg && *idx==' ') --idx;
        while (idx>=beg && *idx!=' ') {
            --idx;
            ++res;
        }
        
        return res;
    }
};

int main() {
    Solution solu;
    string s;
    int res;
    char ch;

    cout<<"Input a string: ";
    while (cin.get(ch)) {
        if (ch == '\n') break;
        s.push_back(ch);
    }

    res = solu.lengthOfLastWord(s);

    cout<<res<<endl;
}