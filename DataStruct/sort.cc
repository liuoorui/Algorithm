#include <iostream>
using namespace std;

void printNums(int *nums, int n) {
    for (int i=0; i<n; ++i) cout<<nums[i]<<" ";
    cout<<endl;
}

void swap(int* nums, int first, int second) {
    if (first == second) return;
    nums[first] = nums[first]^nums[second];
    nums[second] = nums[first]^nums[second];
    nums[first] = nums[first]^nums[second];
}

void siftdown(int* A, int n, int i) {
    int child, temp = A[i];

    while (i < n) {
        child = 2*(i+1)-1;
        if (child >= n) break;
        if (child+1<n && A[child]<A[child+1])
            ++child;

        if (A[child] <= temp) 
            break;

        A[i] = A[child];
        i = child;
    }
    A[i] = temp;
}

void heap_sort(int* A, int n) {
    for (int i=n/2-1; i>=0; --i)
        siftdown(A, n, i);

    for (int i=n-1; i>0; --i) {
        swap(A[0], A[i]);
        siftdown(A, i, 0);
    }
}
void BubbleSort(int* nums, int n) {
    bool sign = 1;

    for (int i=n-1; i>=0 && sign; --i) {
        sign = 0;
        for (int j=0; j<i; ++j) {
            if (nums[j] > nums[j+1]) {
                nums[j] = nums[j]^nums[j+1];
                nums[j+1] = nums[j]^nums[j+1];
                nums[j] = nums[j]^nums[j+1];

                sign = 1;
            }
        }
    }
}

void SelectSort(int* nums, int n) {
    for (int i=0; i<n; ++i) {
        int min_idx = i;
        for (int j=i+1; j<n; ++j) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }

        if (i != min_idx) {
            nums[i] = nums[i]^nums[min_idx];
            nums[min_idx] = nums[i]^nums[min_idx];
            nums[i] = nums[i]^nums[min_idx];
        }
    }
}

void InsertSort(int* nums, int n) {
    // 有时间再熟悉一下；
    // 边界容易写错；
    // 内循环也可以写成前后两两交换，但是耗时就会大一点；
    for (int i=1; i<n; ++i) {
        int temp = nums[i], j;

        for (j=i-1; j>=0 && nums[j]>temp; --j)
            nums[j+1] = nums[j];

        nums[j+1] = temp;
    }
}

void ShellSort(int* nums, int n) {
    int h;
    for (h=1; h<n/9; h=3*h+1){};

    for (; h>0; h/=3) {
        // 里面部分其实是一个步长为h的选择排序；
        // 利用了简单选择排序在基本有序时候复杂度较低的特点；
        for (int i=h; i<n; ++i) {
            int temp = nums[i], j;

            for (j=i-h; j>=0 && nums[j]>temp; j-=h)
                nums[j+h] = nums[j];

            nums[j+h] = temp;
        }
    }
}

void merge(int* nums, int first, int mid, int last) {
    int length = last - first + 1;
    int* result = (int*) malloc(length*sizeof(int));
    int i = first, j = mid+1, k = 0;

    while (i<=mid && j<=last) {
        if (nums[i] < nums[j]) 
            result[k++] = nums[i++];
        else
            result[k++] = nums[j++];
    }

    if (j<=last) i = j;
    while (k < length)
        result[k++] = nums[i++];

    for (k=0; k<length; ++k)
        nums[first+k] = result[k];
    free(result);
}

void MergeSort(int* nums, int first, int last) {
    if (first >= last) return;

    int mid = first + (last-first)/2;
    MergeSort(nums, first, mid);
    MergeSort(nums, mid+1, last);
    merge(nums, first, mid, last);
}

void QuickSort(int* nums, int beg, int end) {
    if (beg >= end) return;
    int i = beg, j = end, t = nums[beg];

    while (1) {
        do ++i; while (i<end && nums[i]<t);
        do --j; while (nums[j]>t);

        if (i >= j) break;
        swap(nums, i, j);
    }
    swap(nums, beg, j);

    QuickSort(nums, beg, j);
    QuickSort(nums, j+1, end);
}

int lower_bound(int* nums, int n, int val) {
    int beg = 0, end = n;

    while (beg < end) {
        int mid = beg + (end-beg)/2;
        if (nums[mid] < val) beg = mid + 1;
        else end = mid;
    }

    return beg;
}

int main() {
    int n;
    cout<<"input the size of array: ";
    cin>>n;
    int *nums = (int*) malloc(n*sizeof(int));
    cout<<"input "<<n<<" nums: ";
    for (int i=0; i<n; ++i) cin>>nums[i];

    cout<<"nums: ";
    printNums(nums, n);

    // BubbleSort(nums, n);
    // SelectSort(nums, n);
    // InsertSort(nums, n);
    // ShellSort(nums, n);
    // MergeSort(nums, 0, n-1);
    // QuickSort(nums, 0, n);
    cout<<lower_bound(nums, n, 3)<<endl;    

    cout<<"sorted: ";
    printNums(nums, n);
}