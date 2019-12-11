// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root, 1, ans);
        return ans;
    }
private:
    void traverse(const TreeNode* root, int level, vector<int>& side_view) {
        if (!root) return;
        if (side_view.size() < level)
            side_view.push_back(root->val);
        else
            side_view[level - 1] = root->val;

        ++level;
        traverse(root->left, level, side_view);
        traverse(root->right, level, side_view);
    }
};
