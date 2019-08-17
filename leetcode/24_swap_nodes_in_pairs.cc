#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0), *curr = dummy, 
                *first, *second;
        dummy->next = head;

        while (curr) {
            if (!curr->next || !curr->next->next) break;
            first = curr->next;
            second = first->next;

            curr->next = second;
            first->next = second->next;
            second->next = first;
            
            curr = first;
        }

        return dummy->next;
    }
};

int main() {
    Solution solu;
    int x;
    ListNode *dummy = new ListNode(-1), *curr = dummy, *res;

    cout<<"Input list: ";
    while (cin>>x) {
        curr->next = new ListNode(x);
        curr = curr->next;

        if (cin.get()=='\n') break;
    }

    res = solu.swapPairs(dummy->next);
    
    curr = res;
    while (curr) {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
}