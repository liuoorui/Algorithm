#include <iostream>
using namespace std;

void swap(int* nums, int first, int second) {
    if (first == second) return;
    nums[first] = nums[first]^nums[second];
    nums[second] = nums[first]^nums[second];
    nums[first] = nums[first]^nums[second];
}

void qsort(int* nums, int beg, int end) {
    if (beg >= end) return;
    int p = nums[beg], l = beg, r = end;

    while (1) {
        do ++l; while (l<end && nums[l]<p);
        do --r; while (nums[r] > p);// 必须不能有等于，因为这里包含了到达r==l处的条件；

        if (l >= r) break;
        swap(nums, l, r);
    }
    swap(nums, beg, r);

    qsort(nums, beg, r);
    qsort(nums, r+1, end);
}

int main () {
    int n, i = 0;
    cout<<"Input the array length: ";
    cin>>n;

    int *nums = (int*) malloc (n * sizeof(int));
    while (i < n) cin>>nums[i++];

    cout<<"pre: ";
    for (i=0; i<n; ++i) cout<<nums[i]<<" ";
    cout<<endl;

    qsort(nums, 0, n);

    cout<<"sorted: ";
    for (i=0; i<n; ++i) cout<<nums[i]<<" ";
    cout<<endl;
}