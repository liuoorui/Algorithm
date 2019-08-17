#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        // find the mid node;
        ListNode *fast = head, *slow = head, *mid, 
                *dummy = new ListNode(0), *curr = dummy;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // sort two parts;
        mid = slow->next;
        slow->next = NULL;
        head = sortList(head);
        mid = sortList(mid);
        
        // merge;
        while (head && mid) {
            if (head->val < mid->val) {
                curr->next = head;
                head = head->next;
            } else {
                curr->next = mid;
                mid = mid->next;
            }
            
            curr = curr->next;
        }
        
        if (mid) head = mid;
        while (head) {
            curr->next = head;
            head = head->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};