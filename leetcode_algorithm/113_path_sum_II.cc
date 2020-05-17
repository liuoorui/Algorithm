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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curr;
        
        dfs(res, curr, root, sum);
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int> curr, TreeNode* root, int sum) {
        if (!root) return;
        curr.push_back(root->val);
        
        if (!root->left && !root->right) {
            if (root->val != sum) return;
            res.push_back(curr);
        }
        
        sum -= root->val;
        dfs(res, curr, root->left, sum);
        dfs(res, curr, root->right, sum);
    }
};