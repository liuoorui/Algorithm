#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int res = search(nums, target, 0, nums.size());
		return res;
	}
private:
	int search(vector<int>& nums, int target, int beg, int end) {
		if (beg >= end) return -1;
		int mid = beg + (end-beg)/2;

		if (nums[mid] == target) return mid;

		if (nums[beg] < nums[end-1]) {
			// ordered;
			if (nums[beg]>target || nums[end-1]<target) return -1;
			auto it = lower_bound(nums.begin()+beg, nums.begin()+end, target);
			int pos = it - nums.begin();
			if (pos<end && nums[pos]==target) return pos;
			else return -1;
		} else {
			return max(search(nums, target, beg, mid), 
						search(nums, target, mid+1, end));
		}
	}
};

int main() {
	int n, target;
	vector<int> nums;
	cin>>n;
	while (n--) {
		int curr;
		cin>>curr;
		nums.push_back(curr);
	}
	cin>>target;

	Solution solu;
	int res = solu.search(nums, target);
	cout<<res<<endl;
}
