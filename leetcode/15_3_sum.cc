#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-2; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i], l = i+1, r = nums.size()-1;

            while (l < r) {
                if (nums[l]+nums[r] < target) {
                    ++l;
                } else if (nums[l]+nums[r] > target) {
                    --r;
                } else {
                    res.push_back(vector<int> {nums[i], nums[l++], nums[r--]});
                    while (l>i+1 && nums[l]==nums[l-1]) ++l;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solu;
    vector<vector<int> > res;
    int n, i = 0;
    cout<<"Input the array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Input the array: ";
    while (i < n) cin>>nums[i++];

    res = solu.threeSum(nums);

    cout<<"nums: ";
    for (int num: nums) cout<<num<<" ";
    cout<<endl;

    for (auto vec: res) {
        for (i=0; i<vec.size(); ++i) cout<<vec[i]<<" ";
        cout<<endl;
    }
}