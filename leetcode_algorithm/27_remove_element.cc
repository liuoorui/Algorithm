#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int k = 0;

        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != val)
                nums[k++] = nums[i];
        }

        return k;
    }
};

int main() {
    Solution solu;
    int n, val, res;

    cout<<"Input array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Input the array: ";
    for (int i=0; i<n; ++i) cin>>nums[i];

    cout<<"Input num to be removed: ";
    cin>>val;
    cout<<"val = "<<val<<endl;

    cout<<"Before: ";
    for (int i=0; i<nums.size(); ++i) cout<<nums[i]<<" ";
    cout<<endl;
    res = solu.removeElement(nums, val);

    cout<<"After: ";
    for(int i=0; i<res; ++i) cout<<nums[i]<<" ";
    cout<<endl;
}