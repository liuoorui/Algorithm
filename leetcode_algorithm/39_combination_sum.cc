#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;

        backTrack(candidates, target, 0, res, curr);

        return res;
    }
private:
    void backTrack(vector<int>& candidates, int target, int idx, 
                vector<vector<int>>& res, vector<int> curr) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        for (; idx<candidates.size(); ++idx) {
            int new_target = target - candidates[idx];

            if (new_target < 0) break;

            curr.push_back(candidates[idx]);
            backTrack(candidates, new_target, idx, res, curr);
            curr.pop_back();
        }
    }
};

