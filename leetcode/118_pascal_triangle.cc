#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> pre{1};
        vector<vector<int>> ans;
        if (numRows == 0) return ans;
        ans.push_back(pre);
        
        while (--numRows) {
            vector<int> curr(pre.size()+1, 1);
            
            for (int i=0; i<pre.size()-1; ++i)
                curr[i+1] = pre[i] + pre[i+1];
            
            ans.push_back(curr);
            pre = curr;
        }
        
        return ans;
    }
};