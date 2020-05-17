#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int maxLength = 0;
        dp[0] = true;
        
        for (string str: wordSet) maxLength = max(maxLength, (int)str.size());
        
        for (int r=1; r<=s.size(); ++r) {
            for (int l=r-1; l>=0 && l>=r-maxLength ;--l) {
                if (dp[l] && wordSet.find(s.substr(l, r-l))!=wordSet.end()) {
                    dp[r] = true;
                    break;
                }
            }
        }
        
        return dp.back();
    }
};