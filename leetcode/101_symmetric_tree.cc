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
    bool isSymmetric1(TreeNode* root) {
        // recursive
        if (!root) return true;
        
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric2(TreeNode* root) {
        // iterative
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode *left = q.front(), *right;
            q.pop();
            right = q.front();
            q.pop();
            
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        
        return isSymmetric(left->left, right->right) 
            && isSymmetric(left->right, right->left);
    }
};