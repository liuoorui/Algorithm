#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        if (lists.empty()) return res;
        
        mergeKLists(lists, res);
        
        return res;
    }
private:
    void mergeKLists(vector<ListNode*>& lists, 
                     ListNode*& res) {
        if (lists.size()==1) {
            res = lists[0];
            return;
        }
        
        vector<ListNode*> next_lists;
        
        for (int i=0; i<lists.size(); i+=2) {
            ListNode *merged = lists[i];
            if (i+1 < lists.size())
                merged = merge2Lists(lists[i], lists[i+1]);
            
            next_lists.push_back(merged);
        }
        
        mergeKLists(next_lists, res);
    }
    ListNode* merge2Lists(ListNode* l1, ListNode *l2) {
        ListNode *head = new ListNode(0), *l = head;
        
        while (l1 && l2) {
            ListNode *node = new ListNode(0);
            
            if (l1->val < l2->val) {
                node->val = l1->val;
                l1 = l1->next;
            } else {
                node->val = l2->val;
                l2 = l2->next;
            }
            
            l->next = node;
            l = node;
        }
        
        if (l2) l1 = l2;
        while (l1) {
            ListNode *node = new ListNode(l1->val);
            
            l->next = node;
            l = node;
            l1 = l1->next;
        }
        
        l = head->next;
        free(head);
        return l;
    }
};