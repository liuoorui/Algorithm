#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        
        dfs(res, s, curr, 0);
        
        return res;
    }
private:
    void dfs(vector<vector<string>>& res, string& s, vector<string>& curr, int beg) {
        if (beg == s.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i=beg; i<s.size(); ++i) {
            if (!isPalindrome(s, beg, i)) continue;
            
            curr.push_back(s.substr(beg, i-beg+1));
            dfs(res, s, curr, i+1);
            curr.pop_back();
        }
    }
    bool isPalindrome(string& s, int l, int r) {
        if (l >= r) return l==r;
        
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        
        return true;
    }
};