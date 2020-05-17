class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        
        if (left_depth > right_depth)
            return lcaDeepestLeaves(root->left);
        else if (left_depth < right_depth)
            return lcaDeepestLeaves(root->right);
        else 
            return root;
    }
private:
    int getDepth(const TreeNode *root) {
        if (!root) return 0;
        return max(getDepth(root->left), 
                   getDepth(root->right)) + 1;
    }
};
