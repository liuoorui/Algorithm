#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        Node *curr = root, *pre = NULL, *head = NULL;
        
        while (curr) {
            // for each level;
            while (curr) {
                if (curr->left) {
                    if (!head) {
                        head = curr->left;
                        pre = curr->left;
                    } else {
                        pre->next = curr->left;
                        pre = curr->left;
                    }
                }
                if (curr->right) {
                    if (!head) {
                        head = curr->right;
                        pre = curr->right;
                    } else {
                        pre->next = curr->right;
                        pre = curr->right;
                    }
                }
                curr = curr->next;
            }
            
            curr = head;
            head = NULL;
            pre = NULL;
        }
        
        return root;
    }
};