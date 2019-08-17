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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *curr = root;
        
        while (curr || !s.empty()) {
            while (curr) {
                ans.push_back(curr->val);
                
                s.push(curr);
                curr = curr->right;
            }
            
            curr = s.top();
            s.pop();
            curr = curr->left;
        }
        
        int i = 0, j = ans.size()-1;
        while (i < j) swap(ans[i++], ans[j--]);
        
        return ans;
    }
};