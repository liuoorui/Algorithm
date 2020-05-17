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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0), *pre = dummy, 
            *curr = NULL, *node = head, *temp;
        
        while (node) {
            while (curr && curr->val<node->val) {
                pre = curr;
                curr = curr->next;
            }
            
            temp = node->next;
            node->next = pre->next;
            pre->next = node;
            pre = dummy;
            curr = dummy->next;
            
            node = temp;
        }
        
        return dummy->next;
    }
};