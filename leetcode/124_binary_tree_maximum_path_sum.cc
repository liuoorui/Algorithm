// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        max_sum_ = INT_MIN;
        
        dfs(root);
        return max_sum_;
    }
    
private:
    int dfs(const TreeNode *root) {
        // 返回的是以root为一个端点的向下的路径和。
        if (!root) return 0;
        
        int left_path = max(0, dfs(root->left));
        int right_path = max(0, dfs(root->right));
        int curr_path = left_path + right_path + root->val;
        max_sum_ = max(max_sum_, curr_path);
        
        return max(left_path, right_path) + root->val;
    }
    
    int max_sum_;
};