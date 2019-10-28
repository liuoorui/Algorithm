/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        const ListNode *currA = headA;
        const ListNode *currB = headB;
        
        while (currA != currB) {
            if (currA) currA = currA->next;
            else currA = headB;
            
            if (currB) currB = currB->next;
            else currB = headA;
        }
        
        return const_cast<ListNode *>(currA);
    }
};