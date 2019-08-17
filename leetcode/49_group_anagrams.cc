#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        int idx = 0;
        
        for (string str: strs) {
            string sorted = str;
            int i;
            sort(sorted.begin(), sorted.end());
            
            if (m.find(sorted) == m.end()) {
                m[sorted] = idx++;
                res.push_back(vector<string>());
            }
            res[m[sorted]].push_back(str);
        }
        
        return res;
    }
};