// 面试题25. 合并两个排序的链表
// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
// 
// 示例1：
// 
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4
// 限制：
// 
// 0 <= 链表长度 <= 1000
// 
// 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        unique_ptr<ListNode> dummy(new ListNode(0));
        auto curr1 = l1, curr2 = l2, curr = dummy.get();
        
        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            
            curr = curr->next;
        }
        
        if (curr1) curr->next = curr1;
        else curr->next = curr2;
        return dummy->next;
    }
};
