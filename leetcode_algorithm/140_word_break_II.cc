#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        vector<string> ans;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        string curr = "";
        int maxLength = 0;
        dp[0] = true;

        for (string str: set) maxLength = max(maxLength, (int)str.size());
        
        for (int r=1; r<=s.size(); ++r) {
            for (int l=r-1; l>=0 && l>=r-maxLength ;--l) {
                if (dp[l] && set.find(s.substr(l, r-l))!=set.end()) {
                    dp[r] = true;
                    break;
                }
            }
        }
        
        if (!dp.back()) return ans;
        
        dfs(ans, set, s, maxLength, curr, 0);
        
        return ans;
    }
private:
    void dfs(vector<string>& ans, unordered_set<string>& set, string& s, 
            const int maxLength, string curr, int idx) {
        if (idx == s.size()) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        for (int i=1; i<=maxLength && idx+i<=s.size(); ++i) {
            string sub_s = s.substr(idx, i);
            if (set.find(sub_s) == set.end()) continue;
            
            curr += sub_s + " ";
            dfs(ans, set, s, maxLength, curr, idx+i);
            curr.erase(curr.end()-i-1, curr.end());
        }
    }
};