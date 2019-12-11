#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> ans(2);
        
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = umap.find(nums[i]);
            
            if (iter != umap.end()) {
                ans[0] = iter->second;
                ans[1] = i;
            } else {
                umap[target - nums[i]] = i;
            }
        }
        
        return ans;
    }
};
int main() {
    int n, target;
    cout<<"input the length of nums: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"input nums: ";
    for (int i=0; i<n; ++i) cin>>nums[i];
    cout<<"input target: ";
    cin>>target;

    Solution solu;
    vector<int> res;

    res = solu.twoSum(nums, target);

    for (int num: res) cout<<num<<" ";
    cout<<endl;
}
