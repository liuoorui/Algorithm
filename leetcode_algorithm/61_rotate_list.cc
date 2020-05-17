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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *curr = head, *tail;
        int leng = 1, cnt;
        
        while (curr->next) {
            ++leng;
            curr = curr->next;
        }
        curr->next = head;

        cnt = leng - k%leng;
        tail = curr;
        curr = head;
        while (cnt--) {
            tail = curr;
            curr = curr->next;
        }
        tail->next = NULL;
        
        return curr;
    }
};