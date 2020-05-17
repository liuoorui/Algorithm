#include <iostream>
using namespace std;

// Definition of singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(0), *curr = head;

        while (l1 && l2) {
            int value = (l1->val+l2->val+carry);
            carry = value / 10;
            value %= 10;

            curr->next =  new ListNode (value);

            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2) l1 = l2;
        while (l1) {
            int value = (l1->val+carry);
            carry = value / 10;
            value %= 10;

            curr->next = new ListNode(value);

            curr = curr->next;
            l1 = l1->next;
        }

        if (carry == 1) {
            curr->next = new ListNode(1);
            curr = curr->next;
        }

        return head->next;
    }
};

int main() {
    ListNode *head1 = new ListNode(0), *head2 = new ListNode(0);
    ListNode *l1 = head1, *l2 = head2;
    int n1, n2;
    
    cout<<"input the length of l1: ";
    cin>>n1;
    cout<<"input "<<n1<<" nums of l1: ";
    for (int i=0; i<n1; ++i) {
        int value;
        cin>>value;
        l1->next = new ListNode(value);
        l1 = l1->next;
    }

    cout<<"input the length of l2: ";
    cin>>n2;
    cout<<"input "<<n2<<" nums of l2: ";
    for (int i=0; i<n2; ++i) {
        int value;
        cin>>value;
        l2->next = new ListNode(value);
        l2 = l2->next;
    }

    Solution solu;
    ListNode *res;
    res = solu.addTwoNumbers(head1->next, head2->next);

    ListNode *curr = res;
    while (curr) {
        cout<<curr->val<<"->";
        curr = curr->next;
    }
    cout<<endl;
}