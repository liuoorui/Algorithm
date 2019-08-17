#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(1, NULL, NULL), *curr = head, *copyed, *tail = dummy;
        
        while (curr) {
            copyed = new Node();
            copyed->next = curr->next;
            curr->next = copyed;
            
            curr = copyed->next;
        }
        
        curr = head;
        while (curr) {
            copyed = curr->next;

            copyed->val = curr->val;
            if (curr->random) copyed->random = curr->random->next;
            else copyed->random = NULL;
            curr = copyed->next;
        }
        
        curr = head;
        while (curr) {
            copyed = curr->next;
            
            curr->next = copyed->next;
            tail->next = copyed;
            tail = copyed;
            
            curr = curr->next;
        }
        
        return dummy->next;
    }
};