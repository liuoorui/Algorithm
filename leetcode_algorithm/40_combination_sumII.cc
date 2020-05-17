#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;

        backTrack(candidates, target, 0, res, curr);

        return res;
    }
private:
    void backTrack(vector<int>& candidates, int target, int idx, 
                vector<vector<int>>& res, vector<int> curr) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (idx == candidates.size()) return;

        for (int i=idx; i<candidates.size(); ++i) {
            if (i!=idx && candidates[i]==candidates[i-1]) continue;

            curr.push_back(candidates[i]);
            backTrack(candidates, target-candidates[i], 
                    i+1, res, curr);
            curr.pop_back();
        }
    }
};