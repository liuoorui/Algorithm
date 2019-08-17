#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ret;

        for (int i=0; i<nums.size(); ++i) {
            if (map.find(nums[i]) != map.end()) {
                ret.push_back(map[nums[i]]);
                ret.push_back(i);
                break;
            }

            map[target-nums[i]] = i;
        }

        return ret;
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
