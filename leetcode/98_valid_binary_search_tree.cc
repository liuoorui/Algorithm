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
    bool isValidBST1(TreeNode* root) {
        // 边界值做法
        return isValid(root, (long)INT_MAX+1, (long)INT_MIN-1);
    }
    bool isValidBST2(TreeNode* root) {
        // 按照BST中序遍历升序的特点
        pre = NULL;
        return isValid(root);
    }
private:
    TreeNode *pre;
    bool isValid(TreeNode* root) {
        if (!root) return true;
        if (!isValid(root->left)) return false;
        
        if (pre && root->val<=pre->val) return false;
        pre = root;
        
        return isValid(root->right);
    }
    bool isValid(TreeNode* node, long upper_bound, long lower_bound) {
        if (!node) return true;
        if (node->val>=upper_bound || node->val<=lower_bound)
            return false;
        
        return isValid(node->left, (long)node->val, lower_bound) &&
            isValid(node->right, upper_bound, (long)node->val);
    }
};