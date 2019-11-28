class Solution {
public:
//     TreeNode* convertBST(TreeNode* root) {
//         if (!root) return root;
//         convertBST(root->right);
//         curr_sum_ += root->val;
//         root->val = curr_sum_;
//         convertBST(root->left);
        
//         return root;
//     }
    
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->right;
            }
            
            curr = stk.top();
            stk.pop();
            curr_sum_ += curr->val;
            curr->val = curr_sum_;
            
            curr = curr->left;
        }
        
        return root;
    }
private:
    int curr_sum_ = 0;
};
