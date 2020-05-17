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
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
private:
    int depth(TreeNode* root) {
        if (!root) return 0;
        int left = depth(root->left),
            right = depth(root->right);
        if (left==-1 || right==-1) return -1;
        if (abs(left-right) > 1) return -1;
        
        return max(left, right) + 1;
    }
};