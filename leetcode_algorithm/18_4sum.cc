#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;

            for (int j=i+1; j<nums.size(); ++j) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;

                int l = j+1, r = nums.size()-1;
                int t = target - nums[i] - nums[j];

                while (l < r) {
                    int sum = nums[l] + nums[r];
                    
                    if (sum < t) ++l;
                    else if (sum > t) --r;
                    else res.push_back(vector<int>{
                        nums[i], nums[j], nums[l++], nums[r--]
                    });

                    while (l>j+1 && nums[l]==nums[l-1]) ++l;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> res;
    int n, target, i = 0;
    cout<<"Input the array length: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Input nums: ";
    while (i < n) cin>>nums[i++];

    cout<<"Input target: ";
    cin>>target;

    res = solu.fourSum(nums, target);

    for (auto vec: res) {
        for (int num: vec) cout<<num<<" ";
        cout<<endl;
    }
}