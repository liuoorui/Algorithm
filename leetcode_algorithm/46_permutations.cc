#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        
        backTrack(nums, res, curr, 0);
        
        return res;
    }
private:
    void backTrack(vector<int>& nums, vector<vector<int>>& res, 
            vector<int> curr, int idx) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i=idx; i<nums.size(); ++i) {
            swap(nums[i], nums[idx]);
            curr.push_back(nums[idx]);
            
            backTrack(nums, res, curr, idx+1);
            
            curr.pop_back();
            swap(nums[i], nums[idx]);
        }
    }
};