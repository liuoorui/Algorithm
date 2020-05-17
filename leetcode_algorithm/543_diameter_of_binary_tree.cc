class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        getDepth(root, diameter);
        return diameter;
    }
    
private:
    int getDepth(const TreeNode* root, int& diameter) {
        if (!root) return 0;
        
        int left_depth = getDepth(root->left, diameter);
        int right_depth = getDepth(root->right, diameter);
        diameter = max(diameter, left_depth + right_depth);
        
        return 1 + max(left_depth, right_depth);
    }
};
