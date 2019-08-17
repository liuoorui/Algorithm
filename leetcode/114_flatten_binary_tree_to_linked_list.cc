#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        
        while (curr) {
            TreeNode *pre = curr->left;
            if (pre) {
                while (pre->right) pre = pre->right;
                
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            
            curr = curr->right;
        }
    }
};