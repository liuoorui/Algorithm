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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* root, int curr) {
        if (!root) return 0;
        curr = curr*10 + root->val;
        if (!root->left && !root->right) return curr;
        
        return dfs(root->left, curr) + 
            dfs(root->right, curr);
    }
};