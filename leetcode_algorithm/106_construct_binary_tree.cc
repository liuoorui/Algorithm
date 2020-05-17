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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size(), 
                        0, postorder.size());
    }
private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, 
                       int in_beg, int in_end, int post_beg, int post_end) {
        if (post_beg == post_end) return NULL;
        int i = 0, val = postorder[post_end-1];
        TreeNode *root = new TreeNode(val);
        
        while (inorder[in_beg+i] != val) ++i;
        
        root->left = buildTree(inorder, postorder, in_beg, in_beg+i, 
                              post_beg, post_beg+i);
        root->right = buildTree(inorder, postorder, in_beg+i+1, in_end, 
                               post_beg+i, post_end-1);
        
        return root;
    }
};