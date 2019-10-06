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
        queue<TreeNode *>   que;
        vector<int>         res;
        
        if (!root) return res;
        que.push(root);
        que.push(nullptr);
        
        while (!que.empty()) {
            TreeNode *curr;
            int       val;
            while (curr = que.front()) {
                val = curr->val;
                que.pop();
                if (curr->left)
                    que.push(curr->left);
                if (curr->right)
                    que.push(curr->right);
            }
            que.pop();
            if (!que.empty())
                que.push(nullptr);
            
            res.push_back(val);
        }
        
        return res;
    }
};