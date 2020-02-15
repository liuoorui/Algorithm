#include <iostream>
using namespace std;

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

void print(int* A, int n) {
    for (int i=0; i<n; ++i)
        cout<<A[i]<<" ";
    cout<<endl;
}

void qsort(int* A, int beg, int end) {
    if (beg >= end) return;
    int i = beg, j = end, q = A[beg];

    while (1) {
        do ++i; while (i<end && A[i]<q);
        do --j; while (A[j]>q);

        if (i >= j) break;
        swap(A[i], A[j]);
    }
    swap(A[beg], A[j]);

    qsort(A, beg, j);
    qsort(A, j+1, end);
}

int main() {
    int A[10] = {7,6,5,3,3,2,1,9,8,7};

    cout<<"before: ";
    print(A, 10);

    heap_sort(A, 10);
    // qsort(A, 0, 10);

    cout<<"sorted: ";
    print(A, 10);
}