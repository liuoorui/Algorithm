#include <iostream>
using namespace std;


// Definition of singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head, *last = head, *pre = NULL;
        while (n--) last = last->next;

        while (last) {
            pre = curr;
            curr = curr->next;
            last = last->next;
        }
        
        if (pre) pre->next = curr->next;
        else head = curr->next;
        free(curr);
        
        return head;
    }
};

int main() {
    int n, i = 0, cnt;
    cout<<"Input the list length: ";
    cin>>cnt;

    cout<<"Input nodes: ";
    ListNode *head = new ListNode(0), *pre = head;
    while (cnt--) {
        int val;
        cin>>val;
        ListNode *curr = new ListNode(val);

        pre->next = curr;
        pre = curr;
    }

    cout<<"Input n: ";
    cin>>n;

    Solution solu;
    ListNode *res_head = solu.removeNthFromEnd(head->next, n), *curr = res_head;

    while (curr) {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
}