#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited = (bool*) malloc(nums.size()*sizeof(bool));
        memset(visited, 0, sizeof(visited));
        vector<vector<int>> res;
        vector<int> curr;
        
        backTrack(nums, res, curr);
        
        return res;
    }
private:
    bool *visited;
    void backTrack(vector<int>& nums, vector<vector<int>>& res, 
                  vector<int> curr) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i=0; i<nums.size(); ++i) {
            if (i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
            if (visited[i]) continue;
            
            visited[i] = 1;
            curr.push_back(nums[i]);
            
            backTrack(nums, res, curr);
            
            curr.pop_back();
            visited[i] = 0;
        }
    }
};

int main() {
    Solution solu;
    int x;
    vector<int> nums;
    vector<vector<int>> res;

    cout<<"Input nums: ";
    while (cin>>x) {
        nums.push_back(x);
        if (getchar() == '\n') break;
    }

    res = solu.permuteUnique(nums);

    for (auto elem: res) {
        for (int num: elem) 
            cout<<num<<" ";

        cout<<endl;
    }
}