#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
	return a > b;
}
void print_nums(int* nums, int n) {
	for (int i=0; i<n; ++i) cout<<nums[i]<<" ";

	cout<<endl;
}

int main() {
	int nums[10] = {9,8,7,6,5,4,3,2,1,0};
	for (int i=2; i<=10; ++i) {
		push_heap(nums, nums+i, comp);
		print_nums(nums, 10);
	}
	print_nums(nums, 10);
}
