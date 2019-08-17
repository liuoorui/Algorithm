#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string curr = "";
        
        dfs(res, s, curr, 0, 0);
        
        return res;
    }
private:
    void dfs(vector<string>& res, string& s, string curr, 
            int idx, int count) {
        if (count == 4) {
            if (idx == s.size()) {
                curr.pop_back();
                res.push_back(curr);
            }
            return;
        }
        
        for (int cnt=1; cnt<=3 && idx+cnt<=s.size(); ++cnt) {
            string str = s.substr(idx, cnt);
            int num = atoi(str.c_str());
            if (num > 255) break;
            
            dfs(res, s, curr+str+".", idx+cnt, count+1);
            
            if (num == 0) break;
        }
    }
};