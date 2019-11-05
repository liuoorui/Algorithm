struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int idx = 0;
        const TreeNode* k_node = midOrderTraverse(root, k, idx);
        
        return k_node->val;
    }
private:
    const TreeNode* midOrderTraverse(const TreeNode* root, int k, int& idx) {
        if (!root) return nullptr;
        const TreeNode* node = midOrderTraverse(root->left, k, idx);
        
        if (node) return node;
        if (++idx == k) return root;
        return midOrderTraverse(root->right, k, idx);
    }
};
