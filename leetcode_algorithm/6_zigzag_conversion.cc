#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret = "";
        int dist = numRows * 2 - 2, leng = s.size();
        int jump1 = dist, jump2 = 0;

        for (int i=0; i<numRows; ++i) {
            int curr = i;
            
            ret.push_back(s[curr]);
            while (curr < leng) {
                if (jump1) {
                    curr += jump1;
                    if (curr < leng) ret.push_back(s[curr]);
                }
                if (jump2) {
                    curr += jump2;
                    if (curr < leng) ret.push_back(s[curr]);
                }
            }

            jump1 -= 2;
            jump2 += 2;
        }

        return ret;
    }
};

int main() {
    string s, res;
    int numRows;
    Solution solu;
    
    cout<<"input a string: ";
    cin>>s;
    cout<<"input row number: ";
    cin>>numRows;

    res = solu.convert(s, numRows);

    cout<<res<<endl;
}