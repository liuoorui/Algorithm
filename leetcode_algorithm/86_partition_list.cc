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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy_less = new ListNode(0), *dummy_great = new ListNode(0),
            *tail_less = dummy_less, *tail_great = dummy_great, *curr = head;
        
        while (curr) {
            if (curr->val < x) {
                tail_less->next = curr;
                tail_less = curr;
                curr = curr->next;
                tail_less->next = NULL;
            } else {
                tail_great->next = curr;
                tail_great = curr;
                curr = curr->next;
                tail_great->next = NULL;
            }
        }
        
        tail_less->next = dummy_great->next;
        return dummy_less->next;
    }
};