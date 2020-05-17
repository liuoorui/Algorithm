#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return 1;
		int maxLength = 1, pre = nums[0], currLength = 1, i = 1;

		while (i < nums.size()) {
			if (nums[i] > pre) {
				pre = nums[i];
				++currLength;
				maxLength = max(maxLength, currLength);
			} else {
				pre = nums[i];
				currLength = 1;
			}

			++i;
		}

		return maxLength;
	}
};

int main() {
	vector<int> nums;
	int n;

	cin>>n;
	while (n--) {
		int curr;
		cin>>curr;
		nums.push_back(curr);
	}

	Solution solu;
	int res = solu.findLengthOfLCIS(nums);
	cout<<res<<endl;
}
