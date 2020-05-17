#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return -1;
        int res = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); ++i) {
            int l = i+1, r = nums.size()-1;
            int curr_sum;

            while (l < r) {
                curr_sum = nums[i] + nums[l] + nums[r];
                if (abs(curr_sum-target) < abs(res-target)) 
                    res = curr_sum;
                
                if (curr_sum < target) ++l;
                else if (curr_sum > target) --r;
                else return res;
            }
        }

        return res;
    }
};

int main() {
    Solution solu;
    int n, i=0, res, target;
    cout<<"Input the array length: ";
    cin>>n;

    cout<<"Input the array: ";
    vector<int> nums(n);
    while (i < n) cin>>nums[i++];

    cout<<"Input the target: ";
    cin>>target;

    res = solu.threeSumClosest(nums, target);

    cout<<res<<endl;
}