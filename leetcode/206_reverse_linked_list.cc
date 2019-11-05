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
    ListNode* reverseList(ListNode* head) {
        // 迭代，时间复杂度O(n)。
        ListNode* r_head = nullptr;
        ListNode* curr = head;
        ListNode* temp = nullptr;
        
        while (curr) {
            temp = curr->next;
            curr->next = r_head;
            r_head = curr;
            
            curr = temp;
        }
        
        return r_head;
    }
    
//     ListNode* reverseList(ListNode* head) {
//         // 递归, 如果不计栈开销，也为O(n)。
//         return reverse(nullptr, head);
//     }

// private:
//     ListNode* reverse(ListNode* pre, ListNode* curr) {
//         if (!curr) return pre;
        
//         ListNode* next = curr->next;
//         curr->next = pre;
//         return reverse(curr, next);
//     }
};