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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left), 
            right = minDepth(root->right);
        if (root->left && root->right) 
            return min(left, right) + 1;
        return left + right + 1;
    }
};