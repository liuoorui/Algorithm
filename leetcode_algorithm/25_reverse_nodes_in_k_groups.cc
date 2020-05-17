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
        if (k < 1) return head;
        ListNode *dummy = new ListNode(-1), 
            *next, *r_head, *tail, *curr = dummy;
        int cnt;
        dummy->next = head;

        while(head) {
            cnt = 0;

            tail = head;
            r_head = reverseK(head, k, &next, cnt);
            if (cnt != k) {
                cnt = 0;
                head = reverseK(r_head, k, &next, cnt);
                curr->next = head;
                break;
            }

            curr->next = r_head;
            tail->next = next;
            head = next;
            curr = tail;
        }

        return dummy->next;
    }
private:
    ListNode* reverseK(ListNode* head, int k, 
            ListNode** next, int& cnt) {
        ListNode *r_head = NULL;

        while (head && cnt<k) {
            ListNode *temp = head->next;

            head->next = r_head;
            r_head = head;
            head = temp;

            ++cnt;
            *next = temp;
        }

        return r_head;
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