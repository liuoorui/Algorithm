// 链表的简单实现；
// 假设链表带头节点；
#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};

int insert(Node *head, int pos, int value) {
    if (!head) return 0;

    Node *curr = head;
    int i=0;
    while (i<pos && curr) {
        curr = curr->next;
        ++i;
    }
    if (!curr && i<pos) return 0;

    Node *p = (Node*) malloc(sizeof(Node));
    p->val = value;

    p->next = curr->next;
    curr->next = p;

    return 1;
}

int push_back(Node *head, int value) {
    if (!head) return 0;
    Node *curr = head;

    while (curr->next) curr = curr->next;

    Node *p = (Node*) malloc(sizeof(Node));
    p->val = value;
    p->next = NULL;

    curr->next = p;

    return 1;
}

int deleteNode(Node *head, int pos) {
    if (!head) return 0;
    Node *curr = head->next, *pre = head;

    while (pos-- && curr) {
        pre = curr;
        curr = curr->next;
    }
    if (!curr) return 0;

    pre->next = curr->next;
    free(curr);

    return 1;
}

void printList(Node *head) {
    if (!head) return;
    Node *curr = head->next;

    while (curr) {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    Node *head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    printList(head);
    insert(head, 0, 1);
    insert(head, 1, 2);
    insert(head, 1, 3);
    push_back(head, 1);
    push_back(head, 2);
    printList(head);

    deleteNode(head, 1);
    cout<<"delete the second"<<endl;
    printList(head);
}