#include <iostream>
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = buildTree(preorder, inorder, 0, preorder.size(), 
                                  0, inorder.size());
        
        return root;
    }
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, 
                       int pre_beg, int pre_end, int in_beg, int in_end) {
        if (pre_beg == pre_end) return NULL;
        int val = preorder[pre_beg], i = 0;
        TreeNode *root = new TreeNode(val);
        
        while (inorder[in_beg+i] != val) ++i;
        
        root->left = buildTree(preorder, inorder, pre_beg+1, pre_beg+i+1, 
                              in_beg, in_beg+i);
        root->right = buildTree(preorder, inorder, pre_beg+i+1, pre_end, 
                               in_beg+i+1, in_end);
        
        return root;
    }
};