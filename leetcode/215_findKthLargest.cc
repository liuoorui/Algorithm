#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		vector<int> heap;
		int i = 0;
		for (; i<k; ++i) heap.push_back(nums[i]);
		
		// min heap;
		make_heap(heap.begin(), heap.end(), comp);
		for (; i<nums.size(); ++i) {
			if (nums[i] <= heap[0]) continue;
			
			pop_heap(heap.begin(), heap.end(), comp);
			heap.back() = nums[i];
			push_heap(heap.begin(), heap.end(), comp);
		}

		return heap[0];
	}
private:
	static bool comp(int a, int b) {
		return a > b;
	}
};

int main() {
	int n, k;
	vector<int> nums;

	cin>>n;
	while (n--) {
		int curr;
		cin>>curr;
		nums.push_back(curr);
	}
	cin>>k;

	Solution solu;
	int res = solu.findKthLargest(nums, k);
	
	cout<<res<<endl;
}
