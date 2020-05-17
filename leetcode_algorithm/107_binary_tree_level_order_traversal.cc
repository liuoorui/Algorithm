#include <iostream>
using namesapce std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root, 1);
        reverse(res.begin(), res.end());
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, TreeNode* root, int level) {
        if (!root) return;
        
        if (res.size() < level) res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        
        dfs(res, root->left, level+1);
        dfs(res, root->right, level+1);
    }
};