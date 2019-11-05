struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // slow为后半段头节点。
        if (pre) pre->next = nullptr;
        ListNode *r_head = nullptr;
        ListNode *temp = nullptr;
        while (slow) {
            temp = slow->next;
            slow->next = r_head;
            r_head = slow;
            slow = temp;
        }
        
        ListNode *curr_l = head;
        ListNode *curr_r = r_head;
        while (curr_l && curr_r) {
            if (curr_l->val != curr_r->val)
                return false;
            
            curr_l = curr_l->next;
            curr_r = curr_r->next;
        }
        
        return true;
    }
};
