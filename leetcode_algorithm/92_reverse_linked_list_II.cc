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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m <= 0) m = 1;
        if (n <= 0) n = 1;
        if (m > n) return head;
        
        ListNode *dummy = new ListNode(-1), *pre, *rHead = NULL, 
        *rTail, *curr = dummy, *temp;
        dummy->next = head;
        int cnt = n - m + 1;
        
        while (--m && curr) 
            curr = curr->next;
        pre = curr;
        curr = curr->next;
        rTail = curr;
        
        while (cnt-- && curr) {
            temp = curr->next;
            curr->next = rHead;
            rHead = curr;
            
            curr = temp;
        }
        
        pre->next = rHead;
        rTail->next = curr;
        
        return dummy->next;
    }
};