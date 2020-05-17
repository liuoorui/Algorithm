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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *curr = root;
        
        while (curr || !s.empty()) {
            
            while (curr) {
                ans.push_back(curr->val);
                
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            
            curr = curr->right;
        }
        
        return ans;
    }
};