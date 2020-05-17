#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *pre = NULL;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);
        pre->next = NULL;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};