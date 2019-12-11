class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (sums_.find(root) != sums_.end()) 
            return sums_[root];
        int ans = root->val;
        
        if (root->left) ans += rob(root->left->left) + rob(root->left->right);
        if (root->right) ans += rob(root->right->left) + rob(root->right->right);
        ans = max(ans, rob(root->left) + rob(root->right));
        sums_[root] = ans;
        return ans;
    }
private:
    unordered_map<TreeNode*, int> sums_;
};
