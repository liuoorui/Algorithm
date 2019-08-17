#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		// 每段连续序列的首尾数字在哈希表中value值存储段长度；
		// 只更新新段的首尾部分；
		unordered_map<int, int> map;
		int res = 0;

		for (int num: nums) {
			if (map[num] != 0) continue;

			int left = map[num-1], right = map[num+1];
			int leng = 1 + left + right;
			map[num] = leng;
			if (map[num-1] != 0) {
				map[num-left] = leng;
			}
			if (map[num+1] != 0) {
				map[num+right] = leng;
			}
		}

		for (auto elem: map) {
			if (elem.second > res) res = elem.second;
		}

		return res;
	}
};

int main() {
	int n;
	vector<int> nums;

	cin>>n;
	while (n--) {
		int curr;
		cin>>curr;
		nums.push_back(curr);
	}

	Solution solu;
	int res = solu.longestConsecutive(nums);

	cout<<res<<endl;
}
