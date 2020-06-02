#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::unique_ptr<ListNode> dummy(new ListNode(0));
        auto pre = dummy.get();
        auto curr = head;
        
        while (curr) {
            if (shorterThanK(curr, k)) {
                pre->next = curr;
                break;
            } else {
                // printf("reverse from %d\n", curr->val);
                pre->next = reverseK(curr, k);
                pre = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
private:
    // 反转k个节点，返回反转后的头节点。
    // 链表长度总是不小于k的。
    ListNode* reverseK(ListNode *head, int k) {
        ListNode *rhead = nullptr;
        ListNode *curr = head, *tail = head;
        
        while (k--) {
            auto next = curr->next;
            curr->next = rhead;
            rhead = curr;
            curr = next;
        }
        
        tail->next = curr;
        return rhead;
    }
    
    bool shorterThanK(const ListNode *head, int k) {
        auto curr = head;
        
        while (curr && --k) {
            curr = curr->next;
        }
        return k != 0;
    }
};

int main() {
    Solution solu;
    ListNode *dummy = new ListNode(-1), *curr = dummy, *res;
    int x, k;

    cout<<"Input list: ";
    while (cin>>x) {
        ListNode *node = new ListNode(x);
        curr->next = node;
        curr = node;
cout<<curr->val<<" ";
        if (cin.get() == '\n') break;
    }
    cout<<"Input k: ";
    cin>>k;

    res = solu.reverseKGroup(dummy->next, k);

    curr = dummy;
    while (curr = curr->next) cout<<curr->val<<" ";
    cout<<endl;
}
