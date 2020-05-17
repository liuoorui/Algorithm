#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *curr = head, *l;

        while (l1 && l2) {
            ListNode *node = new ListNode(0);

            if (l1->val < l2->val) {
                node->val = l1->val;
                l1 = l1->next;
            } else {
                node->val = l2->val;
                l2 = l2->next;
            }

            curr->next = node;
            curr = node;
        }

        if (l2) l1 = l2;
        while (l1) {
            ListNode *node = new ListNode(l1->val);
            curr->next = node;
            curr = node;

            l1 = l1->next;
        }

        l = head->next;
        free(head);
        return l;
    }
};

int main() {
    ListNode *head1 = new ListNode(0), *head2 = new ListNode(0);
    ListNode *l1 = head1, *l2 = head2, *res, *l;
    Solution solu;
    int val;

    cout<<"Input the first list: ";
    while (cin>>val) {
        ListNode *node = new ListNode(val);

        l1->next = node;
        l1 = node;

        char ch = getchar();
        if (ch == '\n') break;
    }

    cout<<"Input the second list: ";
    while (cin>>val) {
        ListNode *node = new ListNode(val);

        l2->next = node;
        l2 = node;

        char ch = cin.get();
        if (ch == '\n') break;
    }

    l1 = head1->next;
    l2 = head2->next;
    free(head1);
    free(head2);

    res = solu.mergeTwoLists(l1, l2);

    l = res;
    while (l) {
        cout<<l->val<<" ";
        l = l->next;
    }
    cout<<endl;
}