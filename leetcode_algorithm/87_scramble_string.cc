#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m != n) return false;
        if (s1 == s2) return true;
        
        memset(cnts, 0, sizeof(cnts));
        for (char ch: s1) ++cnts[ch];
        for (char ch: s2) {
            --cnts[ch];
            if (cnts[ch] < 0) return false;
        }
        
        for (int i=1; i<m; ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) 
               && isScramble(s1.substr(i), s2.substr(i)))
               || (isScramble(s1.substr(0, i), s2.substr(m-i))
               && isScramble(s1.substr(i), s2.substr(0, m-i))))
                return true;
        }
        
        return false;
    }
private:
    int cnts[256];
};

int main() {
    Solution solu;
    string s1, s2;

    cout<<"Input the first string: ";
    cin>>s1;
    cout<<"Input the second string: ";
    cin>>s2;

    bool res = solu.isScramble(s1, s2);

    cout<<res<<endl;
}