#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets1(vector<int>& nums) {
        // 回溯算法
        vector<vector<int>> res;
        vector<int> curr;
        
        dfs(res, curr, nums, 0);
        
        return res;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // 二进制做法，二进制其实按位已经包括了所有组合
        vector<vector<int>> res;
        int all = 1<<nums.size();
        
        for (int i=0; i<all; ++i) {
            vector<int> item;
            int p = 1;
            for (int j=0; j<nums.size(); ++j) {
                if (i & p) item.push_back(nums[j]);
                p <<= 1;
            }
            res.push_back(item);
        }
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& curr, 
            vector<int>& nums, int idx) {
        res.push_back(curr);
        if (idx == nums.size()) return;
        
        while (idx < nums.size()) {
            curr.push_back(nums[idx]);
            dfs(res, curr, nums, ++idx);
            curr.pop_back();
        }
    }
};