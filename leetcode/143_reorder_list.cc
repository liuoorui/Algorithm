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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *fast = head, *slow = head, *curr;
        
        // find the mid node;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // reverse the second part;
        curr = slow->next;
        slow->next = NULL;
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = slow->next;
            slow->next = curr;
            
            curr = temp;
        }
        
        // merge two parts
        fast = head;
        curr = slow->next;
        slow->next = NULL;
        slow = curr;
        while (slow) {
            ListNode *temp = slow->next;
            slow->next = fast->next;
            fast->next = slow;
            
            fast = slow->next;
            slow = temp;
        }
        
        return;
    }
};