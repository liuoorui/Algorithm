#include <iostream>
using namespace std;

int binarySearch(int* nums, int size, int value) {
	int beg = 0, end = size;

	while (beg < end) {
		int mid = beg + (end-beg)/2;

		if (nums[mid] < value) beg = mid + 1;
		else end = mid;
	}

	return beg;
}

int main() {
	int n, *nums;
	cout<<"cin the nums size: "<<endl;
	cin>>n;
	cout<<"cin nums:"<<endl;
	nums = (int*) malloc(n * sizeof(int));
	for (int i=0; i<n; ++i) {
		cin>>nums[i];
	}

	int target;
	cout<<"input the target:"<<endl;
	cin>>target;

	int pos = binarySearch(nums, n, target);
	cout<<"lower_bound = "<<pos<<endl;
}
