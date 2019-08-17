#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;

        dfs(res, curr, n, 1, k);
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& curr, 
             int n, int idx, int k) {
        if (k == 0) {
            res.push_back(curr);
            return;
        }
        
        while (idx <= n) {
            curr.push_back(idx);
            dfs(res, curr, n, ++idx, k-1);
            curr.pop_back();
        }
    }
};