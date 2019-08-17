#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        TreeNode *right = root, *nextRight;
        queue<TreeNode*> q;
        ans.push_back(vector<int>());
        if (root) q.push(root);
        
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left) {
                q.push(curr->left);
                nextRight = curr->left;
            }
            if (curr->right) {
                q.push(curr->right);
                nextRight = curr->right;
            }

            ans.back().push_back(curr->val);
            if (curr == right) {
                right = nextRight;
                ans.push_back(vector<int>());
            }
        }
        
        if (ans.back().empty()) ans.pop_back();
        return ans;
    }
};