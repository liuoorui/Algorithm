#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *curr = root;
        
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            
            res.push_back(curr->val);
            
            curr = curr->right;
        }
        
        return res;
    }
};