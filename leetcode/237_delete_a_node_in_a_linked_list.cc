class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        swap(node->val, next->val);
        
        // delete next.
        node->next = next->next;
        delete next;
        next = nullptr;
    }
};
