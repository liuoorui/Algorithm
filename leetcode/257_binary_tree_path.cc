/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        
        binaryTreePaths(root, "", ans);
        return ans;
    }
    
private:
    void binaryTreePaths(const TreeNode *root, string path, 
                         vector<string> &ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            path += to_string(root->val);
            ans.push_back(path);
        }
        
        path += to_string(root->val) + "->";
        binaryTreePaths(root->left, path, ans);
        binaryTreePaths(root->right, path, ans);
    }
};
