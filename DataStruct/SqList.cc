// 动态顺序表的简单实现；
// 主要是插入和扩容；
#include <iostream>
using namespace std;
#define SIZE 10

typedef struct{
    int *elem;
    int length;
    int ListSize;
}SqList;

int initSqList(SqList *L) {
    L->elem = (int*) malloc(SIZE * sizeof(int));
    if (L->elem == NULL) {
        cout<<("malloc error");
        return 0;
    }
    L->length = 0;
    L->ListSize = SIZE;
    return 1;
}

int expand(SqList *L) {
    L->elem = (int*) realloc(L->elem, L->length * 2 * sizeof(int));
    if (L->elem == NULL)
        exit(EXIT_FAILURE);
    L->ListSize = L->length * 2;

    return 1;
}

int insert(SqList *L, int pos, int value) {
    if (pos<0 || pos>L->length)
        return 0;
    
    if (L->length == L->ListSize)
        expand(L);
    
    for (int i=L->length; i>pos; --i)
        L->elem[i] = L->elem[i-1];
    L->elem[pos] = value;
    ++L->length;

    return 1;
}

int push_back(SqList *L, int value) {
    insert(L, L->length, value);
    
    return 1;
}

void printList(SqList *L) {
    for (int i=0; i<L->length; ++i) 
        cout<<L->elem[i]<<" ";
    cout<<endl;
}

int main(int argc, char** argv) {
    SqList *nums = (SqList*) malloc(sizeof(SqList));
    initSqList(nums);
    cout<<"maxsize = "<<nums->ListSize<<endl;

    for (int i=0; i<10; ++i)
        push_back(nums, i*i);
    printList(nums);
    cout<<"length = "<<nums->length<<endl;
    cout<<"maxsize = "<<nums->ListSize<<endl;

    push_back(nums, 100);
    printList(nums);
    cout<<"length = "<<nums->length<<endl;
    cout<<"maxsize = "<<nums->ListSize<<endl;
}
