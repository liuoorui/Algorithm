#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        dfs(res, digits, 0, "");

        return res;
    }
private:
    char* map[10] = {"", "", "abc", "def", "ghi", "jkl",
                 "mno", "pqrs", "tuv", "wxyz"};

    void dfs(vector<string>& res, string digits, 
        int idx, string curr) {
        if (idx == digits.size()) {
            res.push_back(curr);
            return;
        }
        char* chs = map[digits[idx]-'0'];
        char* it = chs;

        while (*it != 0) {
            curr.push_back(*(it++));
            dfs(res, digits, idx+1, curr);
            curr.pop_back();
        }
    }
};

int main() {
    Solution solu;
    string digits;
    vector<string> res;

    cout<<"Input the digits: ";
    cin>>digits;

    res = solu.letterCombinations(digits);

    for (auto str: res) cout<<"\""<<str<<"\" ";
    cout<<endl;
}