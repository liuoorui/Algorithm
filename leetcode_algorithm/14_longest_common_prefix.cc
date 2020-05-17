#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int i = 0;
        if (strs.empty()) return prefix;

        while (i < strs[0].size()) {
            char ch = strs[0][i];

            for (int j=1; j<strs.size(); ++j) {
                if (i==strs[j].size() || strs[j][i]!=ch)
                    return prefix;
            }

            prefix.push_back(ch);
            ++i;
        }

        return prefix;
    }
};

int main() {
    Solution solu;
    int n;
    string res;
    
    cout<<"How many strings: ";
    cin>>n;
    vector<string> strs(n);
    vector<string>::iterator iter = strs.begin();
    cout<<"Input strings: "<<endl;
    while (iter != strs.end()) cin>>*(iter++);

    res = solu.longestCommonPrefix(strs);

    cout<<"Longest common predix: "<<res<<endl;
}