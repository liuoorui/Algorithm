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
        ListNode *dummy = new ListNode(0), *curr = head, *p = dummy;
        
        while (curr) {
            if (curr->next && curr->val==curr->next->val) {
                while (curr->next && curr->val==curr->next->val) 
                    curr = curr->next;
                curr = curr->next;
                continue;
            }
            
            p->next = curr;
            p = curr;
            curr = curr->next;
            p->next = NULL;
        }
        
        return dummy->next;
    }
};