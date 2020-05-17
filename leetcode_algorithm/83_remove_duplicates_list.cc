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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *curr = head->next, *tail = head;
        
        while (curr) {
            if (curr->val != tail->val) {
                tail->next = curr;
                tail = curr;
            }
            
            curr = curr->next;
            tail->next = NULL;
        }
        
        return head;
    }
};