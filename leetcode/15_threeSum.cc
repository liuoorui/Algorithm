#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3) return res;
		int pos = 0;

		sort(nums.begin(), nums.end());
		while (pos<nums.size()-2 && nums[pos]<=0) {
			if (pos>0 && nums[pos]==nums[pos-1]) {
				++pos;
				continue;
			}
			int i = pos + 1, j = nums.size() - 1;
			int target = 0 - nums[pos];

			while (i < j) {
				if (i>pos+1 && nums[i]==nums[i-1]) {
					++i;
					continue;
				}
				if (j<nums.size()-1 && nums[j]==nums[j+1]) {
					--j;
					continue;
				}

				int curr = nums[i] + nums[j];
				if (curr < target) ++i;
				else if (curr > target) --j;
				else {
					res.push_back(vector<int>{nums[pos], nums[i], nums[j]});
					++i; --j;
				}
			}
			++pos;
		}

		return res;
	}
};

int main() {
	vector<int> nums;
	int n;
	
	cin>>n;
	while (n--){
		int num;
		cin>>num;
		nums.push_back(num);
	}

	Solution solu;
	vector<vector<int>> res = solu.threeSum(nums);

	for (auto vec: res) {
		for (int num: vec) cout<<num<<" ";
		cout<<endl;
	}
}
