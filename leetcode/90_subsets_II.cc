#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        
        dfs(res, nums, curr, 0);
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, 
             vector<int> &curr, int idx) {
        res.push_back(curr);
        if (idx == nums.size()) return;
        
        for (int i=idx; i<nums.size(); ++i) {
            if (i>idx && nums[i]==nums[i-1]) continue;
            
            curr.push_back(nums[i]);
            dfs(res, nums, curr, i+1);
            curr.pop_back();
        }
    }
};