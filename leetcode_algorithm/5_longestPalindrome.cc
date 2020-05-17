#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ss = "$#";
        for (char ch: s) {
            ss.push_back(ch);
            ss.push_back('#');
        }
        int idx = 1, mx = 1, ret_beg, ret_length = -1;
        int *p = (int*) malloc(ss.size()*sizeof(int));
        cout<<ss<<endl;

        for (int i=1; i<ss.size(); ++i) {
            p[i] = i<mx? min(p[2*idx-i], mx-i): 1;

            while (ss[i-p[i]] == ss[i+p[i]]) ++p[i];
            cout<<"i="<<i<<" "<<ss[i]<<" idx="<<idx<<" mx="<<mx<<endl; 
            if (i+p[i] > mx) {
                idx = i;
                mx = i + p[i];
            }

            if (p[i]-1 > ret_length) {
                ret_beg = i - p[i] + 1;
                ret_beg /=2;
                ret_length = p[i] - 1;
            }
        }
        
        cout<<"beg = "<<ret_beg<<" length = "<<ret_length<<endl;
        return s.substr(ret_beg, ret_length);
    }
};

int main() {
    string s;
    cout<<"input a string: ";
    cin>>s;

    Solution solu;
    string res = solu.longestPalindrome(s);

    cout<<res<<endl;
}