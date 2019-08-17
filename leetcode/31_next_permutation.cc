#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2, j = nums.size()-1;

        while (i>=0 && nums[i]>=nums[i+1]) --i;
        if (i >= 0) {
            while (j>i && nums[j]<=nums[i]) --j;
            swap(nums[i], nums[j]);
        }

        ++i;
        j = nums.size()-1;
        while (i < j) swap(nums[i++], nums[j--]);
    }
};

int main() {
    Solution solu;
    vector<int> nums;
    int x;

    cout<<"Input nums: ";
    while(cin>>x) {
        nums.push_back(x);

        if (cin.get() == '\n') break;
    }

    cout<<"nums: ";
    for (int num: nums) cout<<num<<" ";
    cout<<endl;

    solu.nextPermutation(nums);
    cout<<"next: ";
    for (int num: nums) cout<<num<<" ";
    cout<<endl;
}