class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head, *pre = dummy;
        dummy->next = head;
        
        while (curr) {
            if (curr->val == val) {
                pre->next = curr->next;
                delete curr;
                curr = pre->next;
            } else {
                pre = curr;
                curr = curr->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};
